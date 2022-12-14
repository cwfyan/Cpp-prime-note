//
// Created by wfy on 2022/12/10.
//

#ifndef SRC_HASPTRPV_H
#define SRC_HASPTRPV_H
#include "iostream"
#include "string"

class HasPtrPv {
public:
    HasPtrPv(const std::string &s = std::string() );
    HasPtrPv(const HasPtrPv &hp ) ;
    HasPtrPv& operator=(const HasPtrPv &) ;
    HasPtrPv& operator=(const std::string&) ;
    std::string& operator*();
    ~HasPtrPv();

    size_t ues_count() const ;

private:
    std::string *ps;
    int i;
    size_t *use;
};


#endif //SRC_HASPTRPV_H
