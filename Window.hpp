#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED

#include "Widget.hpp"
#include "SimpleText.hpp"
#include <vector>
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <fstream>


class Window{
protected:
    const unsigned max_X=300;
    const unsigned max_Y=300;
    genv::event ev;
    std::vector<Widget*> widgets;

public:
    Window() {};
    virtual void eventLoop();
};

#endif // WINDOW_HPP_INCLUDED
