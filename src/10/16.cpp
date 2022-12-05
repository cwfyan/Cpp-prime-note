//
// Created by wfy on 2022/12/4.
//

#include "iostream"
#include "fstream"
#include "string"
#include "vector"
#include "algorithm"

void elimpus(std::vector<std::string> &words) {
    std::sort(words.begin(), words.end());
    auto iter = std::unique(words.begin(), words.end());
    words.erase(iter, words.end());
}
void biggies (std::vector<std::string> &words,
        std::vector<std::string>::size_type sz,
        std::ostream & out){
    elimpus(words);

    std::stable_sort(words.begin(), words.end(), [](const std::string &a, const std::string &b)->bool {
        return a.size() < b.size();
    });

    auto iter = std::find_if(words.begin(), words.end() ,[sz](const std::string &s) -> bool {
        return s.size() >= sz;
    });
    int count = words.end() - iter;
    std::cout << count << " elements bigger than " << sz <<std::endl;
    std::for_each(iter, words.end(), [&out](const std::string &s){
        out << s <<std::endl;
    });
}
int main(int argc, char * argv[] ){
    if (argc < 3) {
        std::cerr << "please input filename" << std::endl;
        exit(1);
    }
    std::ifstream in(argv[1]);
    std::ofstream out(argv[2]);

    std::vector<std::string> words;
    std::string::size_type sz = 5;
    std::string temp;
    while (in >> temp) {
        words.emplace_back(temp);
    }
    biggies(words, sz, out);
}