//
// Created by wfy on 2022/12/13.
//

#include "HasPtr.h"
#include "utility"

int main()
{
    HasPtr hp("12") ;
    HasPtr hp2("13") ;
    hp = std::move(hp2);

}