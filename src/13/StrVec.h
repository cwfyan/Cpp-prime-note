//
// Created by wfy on 2022/12/11.
//

#ifndef SRC_STRVEC_H
#define SRC_STRVEC_H

#include <memory>
#include <iostream>
class StrVec {
    friend bool operator == (const StrVec &lhs, const StrVec &rhs);
    friend bool operator != (const StrVec &lhs, const StrVec &rhs);
public:
    StrVec():element(nullptr),first_free(nullptr),cap(nullptr){}
    StrVec(const StrVec &);
    StrVec& operator = (const StrVec &);
    StrVec(StrVec &&) noexcept ;
    StrVec& operator = (StrVec &&) noexcept ;
    StrVec(std::initializer_list<std::string> il) ;
    ~StrVec();
    void push_back(const std::string &str);
    void pop_back();
    size_t size() const ;
    size_t capacity() const ;
    std::string * begin() const ;
    std::string * end() const ;
    std::string  at(size_t );
    void reserve(size_t size);
    void resize(const size_t size , const std::string &str = "");

private:
    static std::allocator<std::string> alloc;
    void chk_n_alloc() {
        if ( size() == capacity() ) reallocate(std::max(capacity()*2,1ull));
    }
    std::pair<std::string *, std::string *> alloc_n_cop(const std::string *,const std::string *) ;
    void free();
    void reallocate(size_t );
    std::string *element;
    std::string *first_free;
    std::string *cap;
};


#endif //SRC_STRVEC_H
