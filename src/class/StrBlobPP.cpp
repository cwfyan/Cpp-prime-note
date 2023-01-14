//
// Created by wfy on 2022/12/15.
//

#include "StrBlobPP.h"
#include "StrBlobPtr.h"

std::string *StrBlobPP::operator->() {
    return ptr->operator->();
}
