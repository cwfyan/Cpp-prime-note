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
int main(int argc, char *argv[])
{
    std::shared_ptr<int> sharedPtr = std::make_shared<int>( 12);
    std::weak_ptr<int> weakPtr(sharedPtr);
    std::cout << sharedPtr.use_count() << std::endl;
    auto p = weakPtr.lock();
    std::cout << sharedPtr.use_count() << std::endl;
}