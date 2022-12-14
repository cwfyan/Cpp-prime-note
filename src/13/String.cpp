//
// Created by wfy on 2022/12/12.
//

#include "String.h"
#include <cstring>
#include <algorithm>
std::allocator<char> String::alloc;

String::String(const char *str):sz(std::strlen(str)) ,first_element(alloc.allocate(sz)){
    std::uninitialized_copy(str,str+sz,first_element);
//    std::cout << "执行一般构造"<<std::endl;
}

String::String(const String &str) : sz(str.sz), first_element(alloc.allocate(sz)){
    std::uninitialized_copy(str.begin(), str.end() ,first_element);
//    std::cout << "执行拷贝构造"<<std::endl;
}

String& String::operator = (const String & rhs){
    auto p = alloc.allocate(rhs.sz);
    std::uninitialized_copy(rhs.begin(), rhs.end() ,p);
    free();
    first_element = p;
    sz = rhs.sz;
//    std::cout << "执行赋值"<<std::endl;
    return *this;
}

char *String::begin() const {
    return first_element;
}

char *String::end() const {
    return first_element + sz;
}

size_t String::size() const {
    return sz;
}

void String::free() {
    std::for_each(first_element, first_element + sz ,[](char &c) {alloc.destroy(&c);} );
    alloc.deallocate(first_element , sz);
//    std::cout << "内存释放" << std::endl;
}

String::~String() {
    free();
}

String::String(String &&s) noexcept :first_element(s.first_element),sz(s.sz){
    s.first_element = nullptr;
    s.sz = 0;
    std::cout << "执行移动构造"<<std::endl;
}

String &String::operator = (String &&rhs) noexcept {
    if (&rhs != this) {
        free();
        first_element = rhs.first_element;
        sz = rhs.sz;
        rhs.first_element = nullptr;
        rhs.sz = 0;
    }
    std::cout << "执行移动赋值"<<std::endl;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const String &str) {
    for (auto i = 0; i < str.sz; ++i) {
        putchar(*(str.first_element + i ));
    }
    return os;
}

bool operator==(const String &lhs, const String &rhs) {
    if (lhs.size() != rhs.size()) return false ;
    for (auto p1 = lhs.begin() ,p2 = rhs.begin(); p1!=lhs.end() && p2 != rhs.end() ; ++p1, ++p2) {
        if (*p1 != *p2) return false;
    }
    return true;
}

bool operator!=(const String &lhs, const String &rhs) {
    return !(lhs == rhs);
}

