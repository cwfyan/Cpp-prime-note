//
// Created by wfy on 2022/11/26.
//

#ifndef SRC_SCREEN_H
#define SRC_SCREEN_H

#include "iostream"
#include "Sales_data.h"


class Screen {
    friend std::string f(const Screen &scr){ return scr.contents ;}
public:
    typedef std::string::size_type pos;
    Screen() = default;;
    Screen(pos ht, pos wd): height(ht), width(wd),contents(ht*wd,' '){}
    Screen(pos ht, pos wd, char c): height(ht), width(wd),contents(ht*wd,c){}

    char get() const ;
    char get(pos ht,pos wd) const ;

    Screen &disPlay(std::ostream &) ;
    const Screen &disPlay(std::ostream &) const ;

    Screen &set(char );
    Screen &set(pos, pos, char );

    Screen &move(pos r,pos c);

    pos &getHeight(){ return height;}

private:
    pos cur = 0;

    pos height = 1,width = 1;
    std::string contents;
    Sales_data salesData;

    void do_disPlay(std::ostream &os)const { os << contents <<std::endl;  }


};

std::string f() ;



inline
Screen &Screen::move(pos r,pos c)
{
    cur = r*width + c;
    return *this;
}

inline
char Screen::get() const
{
    return contents[cur];
}

inline
char Screen::get(pos r,pos w) const
{
    pos position =  r*width + w;
    return contents[position];
}

inline
Screen &Screen::disPlay(std::ostream &os)
{
    do_disPlay(os);
    return *this;
}
inline
const Screen &Screen::disPlay(std::ostream &os) const
{
    do_disPlay(os);
    return *this;
}


inline
Screen &Screen::set(char c)
{
    contents[cur] = c;
    return *this;
}

inline
Screen &Screen::set(pos row,  pos col, char c)
{
    contents[row*width + col] = c;
    return *this;
}
#endif //SRC_SCREEN_H
