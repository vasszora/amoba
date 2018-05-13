#ifndef SIMPLETEXT_HPP_INCLUDED
#define SIMPLETEXT_HPP_INCLUDED

#include "Widget.hpp"

class SimpleText : public Widget{

protected:
    std::string txt;

public:
    SimpleText(int _x, int _y, int _w,int _h,std::string _txt) : Widget(_x,_y,_w, _h), txt(_txt){draw();};
    virtual void draw() const;
    void eventHandler(genv::event ev) {};
    std::string getValue() {return txt;};
};

#endif // SIMPLETEXT_HPP_INCLUDED
