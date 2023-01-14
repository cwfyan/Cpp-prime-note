//
// Created by wfy on 2022/12/16.
//

#include "iostream"
class IfThenElse {
public:
    IfThenElse(size_t V1 = 0, size_t V2 = 0, size_t V3 = 0) : val1(V1), val2(V2), val3(V3){}
    size_t operator()(size_t x , size_t y , size_t z ) {
        return x ? y : z ;
    }
private:
    size_t val1,val2,val3;
};

int main()
{
    IfThenElse ifThenElse;
    std::cout << ifThenElse(0,2,3);
    std::string s;
}