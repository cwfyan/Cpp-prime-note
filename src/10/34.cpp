//
// Created by wfy on 2022/12/5.
//

#include "iostream"
#include "vector"

void print_vector(std::vector<int>::reverse_iterator beg, std::vector<int>::reverse_iterator ed) {

    for (auto it = beg ; it != ed ; ++it) {
        std::cout << *it <<std::endl;
    }
}
int main(int argc , char * argv[])
{
    std::cout << argv[0] << std::endl;
    std::vector<int> vec = {1,2,3,4,5,6};
    print_vector(vec.rbegin(), vec.rend());
    auto it = vec.begin() + 2;
    it--;
    std::cout << *it << std::endl;
}