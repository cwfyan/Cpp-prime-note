//
// Created by wfy on 2022/12/12.
//

#ifndef SRC_STRING_H
#define SRC_STRING_H

#include <iostream>
#include <memory>

class String {
    friend std::ostream & operator<<(std::ostream &os , const String &str);
    friend bool operator == (const String &lhs ,const String &rhs);
    friend bool operator != (const String &lhs ,const String &rhs);

public:
    String() :first_element(nullptr),sz(0){}
    String(const char *) ;
    String(const String &);
    String(String &&) noexcept ;
    String& operator = (const String &);
    String& operator = (String &&) noexcept ;
    ~String();

    char * begin() const ;
    char * end() const ;
    size_t size() const ;

    char & operator[](size_t) ;
    const char & operator[](size_t) const;
private:
    static std::allocator<char> alloc;
    void free()  ;
    size_t sz;
    char *first_element;
};


std::ostream & operator<<(std::ostream &os , const String &str);
bool operator == (const String &lhs ,const String &rhs);
bool operator != (const String &lhs ,const String &rhs);

#endif //SRC_STRING_H
