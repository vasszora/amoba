#ifndef SIMPLETEXT_HPP_INCLUDED
#define SIMPLETEXT_HPP_INCLUDED

#include "Widget.hpp"

class SimpleText : public Widget{

private:
    std::string txt;

public:
    SimpleText(int _x, int _y, int _w,int _h,std::string _txt) : Widget(_x,_y,_w, _h), txt(_txt){};
    void draw();
    void eventHandler(genv::event ev);
    std::string getValue();
};

#endif // SIMPLETEXT_HPP_INCLUDED
