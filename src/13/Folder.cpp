//
// Created by wfy on 2022/12/11.
//

#include "Folder.h"
#include "Message.h"

Folder::Folder(const Folder &f) :messages(f.messages){
    add_to_Messages(f);
}

Folder &Folder::operator=(const Folder &f) {
    auto msg = f.messages;
    remove_from_Msg();
    messages = msg;
    add_to_Messages(f);
}

Folder::~Folder() {
    remove_from_Msg();
}

void Folder::addMsg(Message *msg) {
    messages.insert(msg);
}

void Folder::remMsg(Message *msg) {
    messages.erase(msg);
}

void Folder::add_to_Messages(const Folder &f) {
    for (auto msg : f.messages) {
        msg->save(*this);
    }
}

void Folder::remove_from_Msg() {
    while (!messages.empty()) {
        auto msg = messages.begin();
        (*msg)->remove(*this);
    }
}
