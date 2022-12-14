//
// Created by wfy on 2022/12/10.
//

#include "HasPtrPv.h"

HasPtrPv::HasPtrPv(const std::string &s):ps(new std::string (s)), i(0), use(new size_t (1)) {}

HasPtrPv::HasPtrPv(const HasPtrPv &hp):ps(hp.ps), i(hp.i), use(hp.use) { ++(*use);}

HasPtrPv & HasPtrPv::operator=(const HasPtrPv & rhs) {
    ++(*rhs.use);
    if (--(*use) == 0) {
        delete use;
        delete ps;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
}

HasPtrPv & HasPtrPv::operator=(const std::string &s) {
    *ps = s;
    i = 0;
    return *this;
}

std::string & HasPtrPv::operator*() {
    return *ps;
}

HasPtrPv::~HasPtrPv() {
    if (--(*use) == 0) {
        delete use;
        delete ps;
    }
}
