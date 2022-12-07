//
// Created by wfy on 2022/12/6.
//

#ifndef SRC_STRBLOB_H
#define SRC_STRBLOB_H

#include "memory"
#include "vector"
#include "string"
class StrBlob {
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type size()const { return data->size(); }
    bool empty() const { return data->empty(); }
    //添加元素
    void push_back(const std::string &str) { data->push_back(str); }
    //删除元素
    void pop_back() ;
    //访问元素
    std::string & front();
    std::string & back();
    std::string & front() const ;
    std::string & back() const ;

private:
    std::shared_ptr<std::vector<std::string> > data;
    void check(size_type i, const std::string &msg) const ;
};


#endif //SRC_STRBLOB_H