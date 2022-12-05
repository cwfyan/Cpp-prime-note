//
// Created by wfy on 2022/12/5.
//

#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <string>

int main(int argc , char * argv[])
{
    if (argc < 2 ) {
        std::cerr << "please input filename" << std::endl;
        exit(1);
    }
    std::fstream in(argv[1]);

    if (in.fail()) {
        std::cerr << "fail load" << std::endl;
        exit(1);
    }

    std::istream_iterator<std::string> istreamIterator(in);
    std::istream_iterator<std::string> eof;
    std::vector<std::string> vec(istreamIterator, eof);

    for (auto x : vec ) {
        std::cout << x << std::endl;
    }
}