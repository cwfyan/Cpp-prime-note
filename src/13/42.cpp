//
// Created by wfy on 2022/12/11.
//
#include <sstream>
#include <fstream>
#include "StrVec.h"
#include "vector"
#include "set"
#include "map"

//TextQuery
class QueryResult;



class TextQuery {

public:
    TextQuery() {}
    TextQuery(std::istream &);
    QueryResult query(const std::string &s) const ;

private:
    std::shared_ptr<StrVec > file;
    std::map<std::string, std::shared_ptr<std::set<int>>> mp;
};

class QueryResult {

    friend void print(std::ostream &,const QueryResult &);
public:
    QueryResult():word(),file(nullptr),st(nullptr){}
    QueryResult(std::string Word,std::shared_ptr<StrVec > File,
                std::shared_ptr<std::set<int> > St):word(Word), file(File),st(St){}
    std::shared_ptr<StrVec > get_file() const;
    std::set<int>::const_iterator begin() const ;
    std::set<int>::const_iterator end() const ;

private:
    std::string word;
    std::shared_ptr<StrVec > file;
    std::shared_ptr<std::set<int> > st;
};


TextQuery::TextQuery(std::istream & in):file(new StrVec()) {
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

void print(std::ostream & out, const QueryResult & result) {
    out <<"elememt occurs " << result.st->size() <<"times" <<std::endl;

    for (auto x : *result.st) {
        std::cout << "(line " << x << ") " << result.file->at(x) <<std::endl;
    }
}
std::shared_ptr<StrVec > QueryResult::get_file() const { return file; }

std::set<int>::const_iterator QueryResult::begin() const {
    return st->cend();
}
std::set<int>::const_iterator QueryResult::end() const {
    return st->cbegin();
}

void runQueries(std::istream &in){
    const TextQuery tq(in);
    while (true) {
        std::string s;
        std::cin>>s;
        if (s == "q") break;
        print(std::cout, tq.query(s));
    }
}
int main()
{
    std::ifstream in("D:\\C++\\CPP prime note\\src\\13\\words.txt");
    runQueries(in);
}