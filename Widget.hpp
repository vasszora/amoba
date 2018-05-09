#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED

#include "graphics.hpp"
#include <iostream>
class Widget{
protected:
    int x,y,width,heigth; //x,y: a helyzete. width,heigth: szelesseg, magassag
    bool focused=false;
public:
    Widget(int _x, int _y,int _w, int _h): x(_x), y(_y), width(_w), heigth(_h) {};
    virtual void draw()=0;
    virtual void eventHandler (genv::event ev)=0;
    virtual std::string getValue()=0;
    bool isFocused(genv::event ev);
    virtual ~Widget() {};
};

#endif // WIDGET_HPP_INCLUDED
