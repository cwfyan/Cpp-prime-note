//
// Created by wfy on 2022/12/4.
//

#include "iostream"
#include "fstream"
#include "vector"
#include "algorithm"

void output_words(std::vector<std::string>::const_iterator beg,
                  std::vector<std::string>::const_iterator ed) {

    for( std::vector<std::string>::const_iterator  it = beg ; it != ed ; it++) {
        std::cout << *it << std::endl;
    }

}

bool cmp(const std::string &str ) {
    return str.size() >= 5;
}
int main(int argc, char * argv[])
{
    if (argc < 2){
        std::cout << "please input filename" << std::endl;
        return -1;
    }
    std::ifstream in(argv[1]);

    if (in.fail()) {
        std::cout << "fail load" << std::endl;
        return -1;
    }

    std::vector<std::string> words;
    std::string temp;
    while(in >> temp) {
        words.push_back(temp);
    }

    output_words(words.begin(), words.end());

    auto it = std::partition(words.begin(), words.end() ,cmp) ;

    output_words(words.begin(), it);
}