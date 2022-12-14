//
// Created by wfy on 2022/12/9.
//



#include "TextQuery.h"
#include "sstream"
#include "QueryResult.h"

TextQuery::TextQuery(std::istream & in):file(new std::vector<std::string>()) {
    std::string temp;
    int line = 0;
    while ( std::getline(in, temp) ) {
        file -> push_back(temp);
        std::istringstream sstrm(temp);
        std::string word;
        while ( sstrm >> word) {
            if (mp.count(word) == 0) {
                mp.insert({word,std::make_shared<std::set<int>>()});
            }
            mp[word] -> insert(line);
        }
        line++;
    }
}

QueryResult TextQuery::query(const std::string &s) const {
    if (mp.count(s) == 0 )  return QueryResult(s, file, std::make_shared<std::set<int>>());
    else return QueryResult(s, file, mp.find(s)->second);
}