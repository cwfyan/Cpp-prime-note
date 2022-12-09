//
// Created by wfy on 2022/12/7.
//

#include "iostream"
#include "vector"
#include "iterator"

std::vector<int> * new_vector() {
    return new (std::nothrow) std::vector<int> ;
}

void read_ints(std::istream &in, std::vector<int> *pv) {
    std::istream_iterator<int> istreamIterator(in),eof;
    while (istreamIterator != eof) {
        pv->push_back(*istreamIterator);
        istreamIterator++;
    }
}

void print_ints(std::ostream &out, std::vector<int> *pv) {
    std::ostream_iterator<int> ostreamIterator(out," ") ;
    for (const auto &x : *pv) {
        ostreamIterator = x;
    }
}
int main()
{
    auto pv = new_vector();
    read_ints(std::cin, pv);
    print_ints(std::cout, pv);
    delete pv;
    pv = nullptr;
}