#include "Widget.hpp"

bool Widget::isFocused(genv::event ev)
{
    using namespace genv;
    if (ev.type==ev_mouse)
    {
        if(ev.pos_x>=x && ev.pos_x<=x+width && ev.pos_y>=y && ev.pos_y<=y+heigth && ev.button==btn_left && !focused)
        {
            return true;
        }
    }
    return false;
}
