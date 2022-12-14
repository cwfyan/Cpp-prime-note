//
// Created by wfy on 2022/12/6.
//

#ifndef SRC_STRBLOB_H
#define SRC_STRBLOB_H

#include "memory"
#include "vector"
#include "string"

class StrBlobPtr;
class StrBlob {
    friend class StrBlobPtr;
    friend bool operator == (const StrBlob &lhs , const StrBlob &rhs);
    friend bool operator != (const StrBlob &lhs , const StrBlob &rhs);
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    StrBlob(const StrBlob &);
    StrBlob& operator = (const StrBlob &) ;
    size_type size()const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const std::string &str) { data->push_back(str); }
    void push_back(const std::string &&str) { data->push_back(std::move(str)); }
    void pop_back() ;
    std::string & front();
    std::string & back();
    std::string & front() const ;
    std::string & back() const ;
    StrBlobPtr begin();
    StrBlobPtr end();

private:
    std::shared_ptr<std::vector<std::string> > data;
    void check(size_type i, const std::string &msg) const ;
};


#endif //SRC_STRBLOB_H
