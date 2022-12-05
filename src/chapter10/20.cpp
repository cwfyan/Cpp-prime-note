//
// Created by wfy on 2022/12/4.
//

#include "iostream"
#include "fstream"
#include "algorithm"
#include "vector"

int main(int argc, char * argv[] ){

    if (argc < 2) {
        std::cerr << "please input filename" << std::endl;
        exit(1);
    }

    std::ifstream in(argv[1]);
    if (in.fail()) {
        std::cerr << "fail load" << std::endl;
        exit(1);
    }
    std::string temp;
    std::vector<std::string> words;
    while ( in >> temp ) {
        words.emplace_back(temp);
    }
    auto x = std::count_if(words.begin(), words.end(),
            [](const std::string &s)->bool {
        return s.size() >5 ;
    });

    std::cout << x << std::endl;
}
