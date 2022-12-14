//
// Created by wfy on 2022/12/12.
//

#include "String.h"
#include "iostream"
int main()
{
    String s1("12");
    String s2;
    s2 = s1;
    std::cout << s2.begin() << std::endl;
    s1 = "ggc";
    std::cout << s1.begin() << std::endl;
}