#include "iostream"
#include "memory"
#include "map"
#include "13/HasPtrPv.h"
#include "13/HasPtr.h"
#include "13/StrVec.h"
#include "utility"
#include "utility"
#include "13/String.h"
#include "cstring"
#include "class/StrBlobPtr.h"
#include "class/StrBlob.h"
#include "class/StrBlobPP.h"
#include "string"
class test{
public:
    test() {
        std::cout << " 默认初始化 " << std::endl;
    }
    test(const char * p) {
        std::cout << " char * " << std::endl;
    }
    test(const std::string &val) {
        std::cout << " string " << std::endl;
    }
    test(const test &test1) {
        std::cout << " 拷贝构造初始化 " << std::endl;
    }
};





