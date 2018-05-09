#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED


#include "Widget.hpp"
#include <iostream>
class Button : public Widget
{
protected:
    bool pushed=false;
    std::string name;
    bool showing=false;

public:
    Button(int _x, int _y,int _w, int _h, std::string _name) : Widget(_x,_y,_w,_h), name(_name) {};
//    virtual void action();
    virtual void draw()=0;
    virtual void eventHandler (genv::event ev)=0;
    std::string getValue() {return name;}

};

#endif // BUTTON_HPP_INCLUDED
