//
// Created by wfy on 2022/11/26.
//

#include "Screen.h"
int x = 10;
inline
Screen &Screen::set(pos row,  pos col, char c)
{
    contents[row*width + col] = c;
    return *this;
}