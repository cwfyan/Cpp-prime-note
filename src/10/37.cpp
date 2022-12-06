//
// Created by wfy on 2022/12/5.
//

#include "iostream"
#include "vector"
#include "list"
#include "algorithm"
int main()
{
    std::vector<int> vec= {1,2,3,4,5,6,7,8,9,10};
    std::list<int> li(std::vector<int>::reverse_iterator(vec.begin()+7),
                      std::vector<int>::reverse_iterator(vec.begin()+2) );
    for ( auto  x : li ) {
        std::cout << x << std::endl;
    }
}