//
// Created by wfy on 2022/12/4.
//

#include "iostream"

int main()
{
    int a = 10, b =17;
    auto sum = [a,b](int c, int d) -> int {
        return a + b + c + d;
    };
    std::cout << sum(1,2) << std::endl;
}