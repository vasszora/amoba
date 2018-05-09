#ifndef NAVIGATIONBUTTON_HPP_INCLUDED
#define NAVIGATIONBUTTON_HPP_INCLUDED

#include <functional>
#include "Button.hpp"

class NavigationButton : public Button
{
private:
    std::function<void()> funct;
    int keycode;
public:
    NavigationButton(int _x, int _y, int _w, int _h, std::string _name, std::function<void()> _f, int _key) : Button(_x,_y,_w,_h,_name), funct(_f), keycode(_key){};
    void action()
    {
        showing=false;
        funct();
    }
    void eventHandler(genv::event ev);
    void draw();
    //bool isShowing() {return showing;};
};

#endif // NAVIGATIONBUTTON_HPP_INCLUDED
