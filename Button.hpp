#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED


#include "Widget.hpp"
#include <functional>
#include <iostream>
class Button : public Widget
{
protected:
    std::string name;
    std::function<void()> funct;

public:
    Button(int _x, int _y,int _w, int _h,std::string _name, std::function<void()> _f) : Widget(_x,_y,_w,_h), name(_name), funct(_f) {};
    void action()
    {
        funct();
    }
    virtual void draw() const =0;
    virtual void eventHandler (genv::event ev)=0;
    std::string getValue() {return name;}

};

#endif // BUTTON_HPP_INCLUDED
