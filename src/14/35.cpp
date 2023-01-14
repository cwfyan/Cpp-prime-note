//
// Created by wfy on 2022/12/16.
//

#include <fstream>
#include "iostream"
#include "vector"
#include "algorithm"

class ReadString{
public:
    ReadString(std::istream &is = std::cin) :is(is) {};
    std::string operator()(){
        std::string line = "";
        std::getline(is, line);
        return line;
    }
    bool end() {
        return is.fail();
    }
private:
    std::istream &is;
};

int main()
{
    std::ifstream in(R"(D:\C++\CPP prime note\src\14\storyDataFile.txt)");
    ReadString rd(in);
    std::vector<std::string> vec;
    while (  !rd.end() ) {
        vec.push_back(rd());
        std::cout << vec.back() << std::endl;
    }
    std::cout << vec.back() << std::endl;
}