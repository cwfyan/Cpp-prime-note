//
// Created by wfy on 2022/12/11.
//

#include "Message.h"
#include "Folder.h"
Message::Message(const Message &message) : contents(message.contents),folders(message.folders)
{
    add_to_Folders(message);
}

Message &Message::operator=(const Message &message) {
    remove_from_Folders();
    contents = message.contents;
    folders = message.folders;
    add_to_Folders(message);
    return *this;
}

Message::~Message() {
    remove_from_Folders();
}

void Message::save(Folder &f) {
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f) {
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &m) {
    for( auto f : m.folders) {
        f->addMsg(this);
    }
}

void Message::remove_from_Folders() {
    for ( auto f : folders ) {
        f->remMsg(this);
    }
}

void swap(Message &lhs, Message &rhs) {
    lhs.remove_from_Folders();
    rhs.remove_from_Folders();
    std::swap(lhs.contents,rhs.contents);
    std::swap(lhs.folders,rhs.folders);
    for ( auto f : lhs.folders ) {
        f->addMsg(&lhs);
    }
    for ( auto f : rhs.folders ) {
        f->addMsg(&rhs);
    }
}
