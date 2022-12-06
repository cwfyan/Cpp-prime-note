#include <map>
#include "Sales_data.h"
#include "fstream"
#include "sstream"
#include "list"
#include "vector"
#include "queue"
#include "algorithm"
#include "functional"
#include "iostream"
#include "iterator"
#include "set"
#include "memory"
#include "Screen.h"



std::shared_ptr<int> f(int x){
    std::shared_ptr<int> ptr (new int (x));
    std::cout << ptr << std::endl;
    return ptr ;
}

extern  int x ;
int main(int argc, char *argv[])
{
    int x = 0x123f;
}