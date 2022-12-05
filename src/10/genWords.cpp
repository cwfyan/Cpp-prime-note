//
// Created by wfy on 2022/12/4.
//

#include <iostream>
#include <fstream>
#include <string>
#include "random"

int main(int argc, char * argv[])
{
//    if (argc < 2 ){
//        std::cout << "please input filename" << std::endl;
//    }
    std::ofstream out("words.txt");
    if (out.fail()) {
        std::cout << "fail load" << std::endl;
        return -1;
    }

    int count = 1000;
    int a = 'a' ,z = 'z';
    while (--count){
        int size = rand()%10 + 1;
        std::string temp;
        while (size --) {
            char c = rand()%(z-a+1) +a;
            temp += c;
        }
        out << temp <<std::endl;
    }
}