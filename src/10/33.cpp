//
// Created by wfy on 2022/12/5.
//
#include <iostream>
#include <iterator>
#include <fstream>


int main(int argc , char * argv[])
{
    if ( argc < 4 ) {
        std::cout << "please input filename " << std::endl;
        exit(-1);
    }
    std::cerr << argv[0] << std::endl;
    std::ifstream in(argv[1]);
    std::ofstream outOdd(argv[2]);
    std::ofstream outEven(argv[3]);

    std::istream_iterator<int> istreamIterator(in), eof;
    std::ostream_iterator<int> ostreamIteratorOdd(outOdd,"\n");
    std::ostream_iterator<int> ostreamIteratorEven(outEven,"\n");

    while (istreamIterator != eof) {
        auto value = *istreamIterator++ ;
        if ( value&1 ) {
            ostreamIteratorOdd = value;
        } else {
            ostreamIteratorEven = value;
        }
    }
}