//
// Created by wfy on 2022/12/9.
//

#ifndef SRC_TEXTQUERY_H
#define SRC_TEXTQUERY_H

#include "vector"
#include "memory"
#include "map"
#include "set"
#include "iostream"
#include "fstream"

class QueryResult;

class TextQuery {

public:
    TextQuery() {}
    TextQuery(std::istream &);
    QueryResult query(const std::string &s) const ;

private:
    std::shared_ptr<std::vector<std::string> > file;
    std::map<std::string, std::shared_ptr<std::set<int>>> mp;
};


#endif //SRC_TEXTQUERY_H
