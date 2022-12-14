//
// Created by wfy on 2022/12/9.
//

#ifndef SRC_HASPTR_H
#define SRC_HASPTR_H
#include "iostream"

class HasPtr {
    friend inline void swap(HasPtr &,HasPtr &);
public:
    HasPtr(const std::string &s = std::string() ) :ps(new std::string (s)),i(0){}
    HasPtr(const char * s ) :HasPtr(std::string(s) )  {}
    HasPtr(const HasPtr &hp ) :ps(new std::string(*hp.ps)),i(hp.i){}
    HasPtr(HasPtr &&hp ) noexcept :ps(hp.ps),i(hp.i){
        hp.ps = nullptr;
    }
    HasPtr& operator=(const HasPtr &) ;
    HasPtr& operator=(const std::string&) ;
    bool operator<(const HasPtr &)  const ;
//    HasPtr& operator=(HasPtr ) ;
    HasPtr& operator=(HasPtr && ) noexcept ;

    ~HasPtr() { delete ps; }

    std::string get_str() const ;
private:
    std::string *ps;
    int i;
};

inline void swap(HasPtr &lhs, HasPtr &rhs) {
    std::cout << "执行swap" <<std::endl;
    std::swap(lhs.ps, rhs.ps);
    std::swap(lhs.i , rhs.i);
}



#endif //SRC_HASPTR_H
