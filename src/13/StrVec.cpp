//
// Created by wfy on 2022/12/11.
//

#include "StrVec.h"
#include "memory"
#include "utility"
#include "algorithm"

std::allocator<std::string> StrVec::alloc;

size_t StrVec::size() const {
    return first_free - element;
}

size_t StrVec::capacity() const {
    return cap - element;
}

std::string *StrVec::begin() const {
    return element;
}

std::string *StrVec::end() const {
    return first_free;
}

std::pair<std::string *, std::string *> StrVec::alloc_n_cop(const std::string *beg,const std::string *ed)  {
    auto data = alloc.allocate(ed - beg);
    return std::pair<std::string *, std::string *>(data,std::uninitialized_copy(beg, ed, data));
}

void StrVec::free() {
    if (element) {
        std::for_each(element, first_free ,[](std::string &s) { alloc.destroy(&s); } );
        alloc.deallocate(element , cap - element);
    }
}

StrVec::StrVec(const StrVec & strVec) {
    auto data = alloc_n_cop(strVec.begin(),strVec.end());
    element = data.first;
    first_free = data.second;
    cap = data.second;
}

StrVec::StrVec(std::initializer_list<std::string> il) {
    auto data = alloc_n_cop(il.begin(),il.end());
    element = data.first;
    first_free = data.second;
    cap = data.second;
}

StrVec &StrVec::operator = (const StrVec &rhs) {
    auto data = alloc_n_cop(rhs.begin(),rhs.end());
    free();
    element = data.first;
    first_free = data.second;
    cap = data.second;
    return *this;
}

StrVec::~StrVec() {
    free();
}

void StrVec::push_back(const std::string &str) {
    chk_n_alloc();
    alloc.construct(first_free++, str);
}

void StrVec::pop_back() {
    if (size() > 0 ) {
        alloc.destroy(--first_free);
    }
}

void StrVec::reallocate(size_t new_capacity) {
    auto new_element = alloc.allocate(new_capacity);
    auto elem = element;
    auto dest = new_element;
    while ( elem != first_free && dest != new_element + new_capacity ) {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    element = new_element;
    first_free = dest;
    cap = new_element + new_capacity;
}

void StrVec::reserve(size_t new_capacity) {
    if (new_capacity <= capacity()) return;
    reallocate(new_capacity);
}

void StrVec::resize(size_t new_size, const std::string &str) {
    while (new_size > size()) {
        push_back(str);
    }
    while (new_size < size()) {
        pop_back();
    }
}

std::string  StrVec::at(size_t index) {
    if (index >= size()) return std::string ();
    return *(element+index);
}

StrVec::StrVec(StrVec && s) noexcept :
element(s.element), first_free(s.first_free), cap(s.cap)
{
    s.element = s.first_free = s.cap = nullptr;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept {
    if (&rhs != this) {
        free();
        element = rhs.element;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.element = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

bool operator==(const StrVec &lhs, const StrVec &rhs) {
    if (lhs.size() != rhs.size()) return false;
    for (auto p1 = lhs.begin(),p2 = rhs.begin(); p1 != lhs.end() && p2 != rhs.end() ; ++p1,++p2) {
        if ( *p1 != *p2) return false;
    }
    return true;
}

bool operator!=(const StrVec &lhs, const StrVec &rhs) {
    return !(lhs == rhs);
}

std::string &StrVec::operator[](size_t n) {
    return element[n];
}

const std::string &StrVec::operator[](size_t n) const {
    return element[n];
}








