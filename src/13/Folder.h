//
// Created by wfy on 2022/12/11.
//

#ifndef SRC_FOLDER_H
#define SRC_FOLDER_H
#include "iostream"
#include "set"

class Message;
class Folder {
    friend class Message;
public:
    Folder() = default;
    Folder(const Folder&);
    Folder& operator = (const Folder&);
    ~Folder();
    void addMsg(Message *);
    void remMsg(Message *);
private:
    std::set<Message *> messages;
    void add_to_Messages(const Folder &);
    void remove_from_Msg();
};


#endif //SRC_FOLDER_H
