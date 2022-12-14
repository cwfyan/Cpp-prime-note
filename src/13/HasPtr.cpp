//
// Created by wfy on 2022/12/9.
//

#include "HasPtr.h"

HasPtr&
HasPtr::operator=(const HasPtr &hp) {
    auto new_str = new std::string (*hp.ps);
    delete ps;
    ps = new_str;
    i = hp.i;
    return *this;
}

HasPtr&
HasPtr::operator=(const std::string &str) {
    *ps = str;
    i = 0;
    return *this;
}

bool
HasPtr::operator<(const HasPtr &rhs) const {
    return *ps < *rhs.ps;
}



std::string HasPtr::get_str() const {
    return *ps;
}

//HasPtr &HasPtr::operator=(HasPtr rhs) {
//    swap(*this,rhs);
//    return *this;
//}

HasPtr &HasPtr::operator=(HasPtr &&rhs) noexcept {
    delete ps;
    ps = rhs.ps;
    rhs.ps = nullptr;
    return *this;
}