//
// Created by wfy on 2022/12/16.
//

#include "iostream"
#include "vector"
#include "string"
#include "vector"
#include "fstream"
#include "iterator"
#include "algorithm"
class Comp{
public:
    Comp(int val) :val(val) {}
    bool operator()(const std::string &str) {
        return str.size() == val;
    }
private:
    int val;
};
void read_to_vec(std::istream &in, std::vector<std::string> &vec) {
    std::istream_iterator<std::string> iterator(in),eof;
    std::copy(iterator, eof, std::back_inserter(vec));
}
void solve()
{
    std::ifstream is (R"(D:\C++\CPP prime note\src\14\words.txt)");
    std::vector<std::string> vec;
    read_to_vec(is , vec);
    for (int len = 1; len <= 10 ; ++len) {
        Comp cmp(len);
        std::cout << "len of " << len << " " << std::count_if(vec.begin(), vec.end(), cmp) << std::endl;
    }
}

