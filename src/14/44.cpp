//
// Created by wfy on 2022/12/16.
//

#include <iostream>
#include <functional>
#include <map>
#include <algorithm>
#include <vector>
class mul {
public:
    int operator () (int x , int y) {
        return x * y;
    }
};

int add(int x,int y) {
    return x + y;
}
int main()
{
    std::map<std::string, std::function<int(int, int )> > mp;
    mp.insert({"+", add});
    mp.insert({"-",[](int x, int y) -> int  { return x - y;}});
    mp.insert({"*", mul()});
    mp.insert({"/",std::divides<int>()});
    std::cout << mp["/"](10,6);
    std::string * a , *b;
    a < b;
}