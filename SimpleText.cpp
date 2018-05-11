#include "SimpleText.hpp"

void SimpleText::draw()
{
    using namespace genv;
    gout << move_to(x,y) << color(0,0,0) << box(width,heigth);
    gout << move_to(x+3, y+17) << color(255,255,255) << text(txt);
    gout << refresh;
}

void SimpleText::eventHandler(genv::event ev)
{

}

