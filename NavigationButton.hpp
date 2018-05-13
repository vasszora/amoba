#ifndef NAVIGATIONBUTTON_HPP_INCLUDED
#define NAVIGATIONBUTTON_HPP_INCLUDED

#include "Button.hpp"

class NavigationButton : public Button
{
private:
    int keycode;
public:
    NavigationButton(int _x, int _y, int _w, int _h, std::string _name, std::function<void()> _f, int _key) : Button(_x,_y,_w,_h,_name,_f), keycode(_key){};
    void eventHandler(genv::event ev);
    void draw();
};

#endif // NAVIGATIONBUTTON_HPP_INCLUDED
