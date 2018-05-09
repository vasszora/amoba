#include "NavigationButton.hpp"

#include <iostream>

void NavigationButton::draw()
{
    using namespace genv;
    gout << move_to(x,y) ;
    gout<< color(0,0,0) ;
    gout<< box(width,heigth) ;
    gout<< move_to(x+3,y+gout.cdescent()+gout.cdescent()+5) ;
    gout<< color(255,255,255) << text(name);
    showing=true;
}
void NavigationButton::eventHandler(genv::event ev)
{
    if((isFocused(ev) && !focused) || ev.keycode==keycode)
    {
        action();
        std::cout<<"naaa"<<std::endl;
        focused=true;
    }
    else
    {
        focused=false;
    }
}
