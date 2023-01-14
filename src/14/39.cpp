//
// Created by wfy on 2022/12/16.
//

#include <iostream>
#include "fstream"
#include "vector"
#include <algorithm>

extern void read_to_vec(std::istream &, std::vector<std::string> &);

class LenBetween{
public:
    LenBetween(int min_len,int max_len) : min_len(min_len) , max_len(max_len){}
    bool operator()(const std::string &str) {
        int len = str.size();
        return len >= min_len && len <= max_len;
    }
private:
    int min_len, max_len;
};
int main()
{
    std::ifstream is (R"(D:\C++\CPP prime note\src\14\words.txt)");
    std::vector<std::string> vec;
    read_to_vec(is , vec);
    LenBetween lenBetween(1,9);
    std::cout << std::count_if(vec.begin(), vec.end(), lenBetween) <<std::endl;
}