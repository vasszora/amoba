#include "Window.hpp"

void Window::eventLoop()
{
    using namespace genv;

    while(gin >> ev)
    {
        for(unsigned i=0; i<widgets.size(); i++)
        {
            widgets[i]->eventHandler(ev);
        }

    }
    for(unsigned i=0; i<widgets.size(); i++)
    {
        delete widgets[i];
    }
}
