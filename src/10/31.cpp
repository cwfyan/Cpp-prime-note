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
    std::ostream_iterator<int> ostreamIterator(std::cout, " ");

    std::vector<int> vec(istreamIterator, eof);
    std::sort(vec.begin() , vec.end());
    std::unique_copy(vec.begin() , vec.end() , ostreamIterator);

}