//
// Created by wfy on 2022/12/16.
//

#include <algorithm>
#include <vector>
#include <iostream>
class Comp {
public:
    Comp(int val):val(val) {}
    bool operator()(int x) {
        return val == x;
    }
private:
    int val;
};

class test {
public:
    test() ;
    test(const test &t) ;
    test(test &&t) noexcept ;

private:
    int *p;
};
int main()
{
//    std::vector<int > vec = {1,1,2,3,1,5,1};
//    int old_value = 1 , nee_value = 100;
//    Comp cmp1(old_value);
//    std::replace_if(vec.begin() , vec.end() , cmp1 , nee_value);
//    for ( auto x : vec ) {
//        std::cout << x << std::endl;
//    }
    test t;
}