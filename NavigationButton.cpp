#include "NavigationButton.hpp"
#include "MyFunctions.hpp"
#include <iostream>

void NavigationButton::draw()
{
    using namespace genv;
    black();
    gout << move_to(x,y) << box(width,heigth) ;
    gout<< move_to(x+3,y+gout.cdescent()+gout.cdescent()+5) ;
    white();
    gout << text(name);
}
void NavigationButton::eventHandler(genv::event ev)
{
    if((isFocused(ev) && !focused) || ev.keycode==keycode) //ha rákattintunk vagy lenyomjuk a hozzátartozó billentyût, elvégzi az actiont
    {
        action();
        focused=true;
    }
    else
    {
        focused=false;
    }
}
