//
// Created by wfy on 2022/12/8.
//

#include "StrBlobPtr.h"
#include "StrBlob.h"

StrBlobPtr::StrBlobPtr(): cur(0) {}
StrBlobPtr::StrBlobPtr(const StrBlob &strBlob, size_type index):ptr(strBlob.data),cur(index) {}

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(size_type index, const std::string &msg) const {
    auto ret = ptr.lock();
    if (ret == nullptr) {
        throw std::out_of_range("Object does not exist");
    }
    if (index >= ret->size() || index < 0) {
        throw std::out_of_range(msg);
    }
    return ret;
}

std::string & StrBlobPtr::deref() const {
    auto p = check(cur, "dereference pass end");
    return (*p)[cur];
}

StrBlobPtr & StrBlobPtr::inc() {
    check(cur, "cur point at the end");
    ++cur;
    return *this;
}

StrBlobPtr & StrBlobPtr::dec() {
    --cur;
    check(cur, "cur point at the begin");
    return *this;
}

bool eq(const StrBlobPtr &a , const StrBlobPtr &b){
    auto ap = a.ptr.lock(),bp = b.ptr.lock();
    if (ap == bp){
        return (!ap) || (a.cur == b.cur);
    }
    return false;
}