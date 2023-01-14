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
    check(cur, "cur pointer at the end");
    ++cur;
    return *this;
}

StrBlobPtr & StrBlobPtr::dec() {
    --cur;
    check(cur, "cur pointer at the begin");
    return *this;
}

bool eq(const StrBlobPtr &a , const StrBlobPtr &b){
    auto ap = a.ptr.lock(),bp = b.ptr.lock();
    if (ap == bp){
        return (!ap) || (a.cur == b.cur);
    }
    return false;
}

std::string &StrBlobPtr::operator[](StrBlobPtr::size_type n) {
    return (*ptr.lock())[n];
}

const std::string &StrBlobPtr::operator[](StrBlobPtr::size_type n) const {
    return (*ptr.lock())[n];
}

StrBlobPtr &StrBlobPtr::operator++() {
    check(cur,"cur pointer at the end");
    ++cur;
    return *this;
}

StrBlobPtr &StrBlobPtr::operator--() {
    --cur;
    check(cur,"cur pointer at the begin");
    return *this;
}

const StrBlobPtr StrBlobPtr::operator++(int) {
    auto ret = *this;
    ++(*this);
    return ret;
}

const StrBlobPtr StrBlobPtr::operator--(int) {
    auto ret = *this;
    --(*this);
    return ret;
}

StrBlobPtr StrBlobPtr::operator+(size_t n) const {
    auto ret = *this;
    ret.cur  += n;
    return ret;
}

StrBlobPtr StrBlobPtr::operator-(size_t n) const {
    auto ret = *this;
    ret.cur  -= n;
    return ret;
}

std::string &StrBlobPtr::operator*() const {
    auto p = check(cur,"deference pass the end");
    return (*p)[cur];
}

std::string *StrBlobPtr::operator->() const {
    return & this->operator*();
}


