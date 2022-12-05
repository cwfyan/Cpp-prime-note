//
// Created by wfy on 2022/12/4.
//

#include "iostream"
#include "algorithm"
#include "list"

int main()
{
    std::vector<int> vec = {1,3,6,1,7,4,5,6,1,2,5};
    std::list<int> li;
    std::sort(vec.begin(), vec.end());
    std::unique_copy(vec.begin(), vec.end(),std::back_inserter(li));

    for( auto x : li ) {
        std::cout << x << std::endl;
    }
}