//
// Created by wfy on 2022/12/10.
//

#include <fstream>
#include "iostream"
#include "vector"
#include "string"
#include "HasPtr.h"
#include "algorithm"
#include "iterator"

int main()
{
    std::ifstream in("D:\\C++\\CPP prime note\\src\\13\\words.txt");
    std::istream_iterator<std::string> istreamIterator(in),eof;

    std::vector<HasPtr> vec(istreamIterator,eof);
    std::sort(vec.begin(),vec.end());
    for (auto x:vec) {
        std::cout << x.get_str() << std::endl;
    }
}