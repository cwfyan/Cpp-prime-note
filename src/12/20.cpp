//
// Created by wfy on 2022/12/8.
//

#include <fstream>
#include "iostream"
#include "../class/StrBlobPtr.h"
#include "../class/StrBlob.h"

int main()
{
    std::ifstream in("D:\\C++\\CPP prime note\\src\\12\\words.txt");
    StrBlob strBlob;
    std::string temp;
    while (std::getline(in, temp) ) {
        strBlob.push_back(temp);
    }
    for (auto p = strBlob.begin(); !eq(p,strBlob.end()); p.inc()){
        std::cout << p.deref() << std::endl;
    }
}