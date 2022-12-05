//
// Created by wfy on 2022/12/5.
//

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

int main()
{
    std::istream_iterator<int> istreamIterator(std::cin), eof ;
    std::vector<int> vec;

    std::copy(istreamIterator, eof, std::back_inserter(vec ));

    std::sort(vec.begin() , vec.end() );
    for (auto x : vec ) {
        std::cout << x <<std::endl;
    }
}