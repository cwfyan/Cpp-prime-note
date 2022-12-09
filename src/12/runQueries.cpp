//
// Created by wfy on 2022/12/9.
//
#include "iostream"
#include "TextQuery.h"
#include "QueryResult.h"

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
    std::ifstream in("D:\\C++\\CPP prime note\\src\\12\\storyDataFile.txt");
    runQueries(in);
}