//
// Created by wfy on 2022/12/11.
//

#ifndef SRC_MESSAGE_H
#define SRC_MESSAGE_H
#include <iostream>
#include "set"
class Folder;
class Message {
    friend class Folder;
    friend void swap(Message &,Message &);
public:
    explicit Message(const std::string &s = "") : contents(s){}
    Message(const Message &message) ;
    Message& operator = (const Message &message) ;
    ~Message();
    void save(Folder &);
    void remove(Folder &);

private:
    std::string contents;
    std::set<Folder *> folders;
    void add_to_Folders(const Message&);
    void remove_from_Folders();
};


#endif //SRC_MESSAGE_H
