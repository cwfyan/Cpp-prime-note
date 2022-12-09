//
// Created by wfy on 2022/12/9.
//

#ifndef SRC_QUERYRESULT_H
#define SRC_QUERYRESULT_H
#include "iostream"
#include "set"
#include "memory"
#include "vector"

class QueryResult {

    friend void print(std::ostream &,const QueryResult &);
public:
    QueryResult():word(),file(nullptr),st(nullptr){}
    QueryResult(std::string Word,std::shared_ptr<std::vector<std::string> > File,
    std::shared_ptr<std::set<int> > St):word(Word), file(File),st(St){}
    std::shared_ptr<std::vector<std::string>> get_file() const;
    std::set<int>::const_iterator begin() const ;
    std::set<int>::const_iterator end() const ;

private:
    std::string word;
    std::shared_ptr<std::vector<std::string> > file;
    std::shared_ptr<std::set<int> > st;
};


#endif //SRC_QUERYRESULT_H
