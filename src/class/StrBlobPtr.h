//
// Created by wfy on 2022/12/8.
//

#ifndef SRC_STRBLOBPTR_H
#define SRC_STRBLOBPTR_H

#include "memory"
#include "vector"
#include "StrBlob.h"


class StrBlob;
class StrBlobPtr {
    friend bool eq(const StrBlobPtr &a , const StrBlobPtr &b);
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlobPtr() ;
    StrBlobPtr(const StrBlob & strBlob , size_type index = 0);
    std::string & deref() const ;
    StrBlobPtr & inc();
    StrBlobPtr & dec();
private:
    std::weak_ptr<std::vector<std::string> > ptr;
    size_type cur;
    std::shared_ptr<std::vector<std::string> >
    check(size_type index ,const std::string &msg) const;
};




bool eq(const StrBlobPtr &a , const StrBlobPtr &b);

#endif //SRC_STRBLOBPTR_H
