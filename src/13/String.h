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
    String& operator = (const String &);
    String(String &&) noexcept ;
    String& operator = (String &&) noexcept ;

    char * begin() const ;
    char * end() const ;
    size_t size() const ;

    void add_char_end();
    ~String();
private:
    static std::allocator<char> alloc;
    void free()  ;
    size_t sz;
    char *first_element;
};


#endif //SRC_STRING_H
