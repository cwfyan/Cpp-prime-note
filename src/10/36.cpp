//
// Created by wfy on 2022/12/5.
//

#include "iostream"
#include "algorithm"
#include "list"
#include "fstream"
#include "iterator"
int main()
{
    std::fstream  in("D:\\C++\\CPP prime note\\src\\10\\number.txt");
    std::istream_iterator<int> istreamIterator(in),eof;
    std::list<int> li(istreamIterator, eof);

    auto rPosition = std::find(li.crbegin(),li.crend(),0);

    if (rPosition == li.rend()) {
        std::cout << "not found" <<std::endl;
    }else {
        auto position = rPosition.base();
        auto iter = li.begin();
        size_t index = 0;
        while (iter != position) {
            index++;iter++;
        }
        std::cout << index <<std::endl;
    }

    return 0;
}