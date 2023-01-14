//
// Created by wfy on 2022/12/15.
//

#ifndef SRC_STRBLOBPP_H
#define SRC_STRBLOBPP_H

#include "memory"
#include "vector"
class StrBlobPtr;
class StrBlobPP {
public:
    StrBlobPP(StrBlobPtr & p) : ptr(&p){}
    StrBlobPtr &operator*();
    std::string *operator->();
private:
    StrBlobPtr * ptr;
};


#endif //SRC_STRBLOBPP_H
