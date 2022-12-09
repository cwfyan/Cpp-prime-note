//
// Created by wfy on 2022/11/26.
//

#include "Screen.h"

inline
Screen &Screen::set(pos row,  pos col, char c)
{
    contents[row*width + col] = c;
    return *this;
}