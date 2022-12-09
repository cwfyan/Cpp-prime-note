#include "iostream"
#include "memory"
#include "map"
int main(int argc, char *argv[])
{
    std::map<int,int> mp = {{1,2},{2,3}};
    std::cout << mp.find(99)->first <<std::endl;
}