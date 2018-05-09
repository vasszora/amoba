#include "Window.hpp"

Window::Window()
{
//    using namespace genv;
//    srand(time(0));
//    gout.open(max_X,max_Y);
//    gout<<color(255,250,250)<<move_to(0,0)<<box(max_X, max_Y)<<refresh;
//    int sizeOfLine=gout.cdescent()+gout.cascent();
}

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

//std::string Window::longestString (std::vector<std::string> elements)
//{
//    //a menu szelessegehez kell
//    std::string longest=elements[0];
//    for(unsigned int i=0; i<elements.size(); i++)
//    {
//        if(elements[i].length()>longest.length())
//        {
//            longest=elements[i];
//        }
//    }
//    return longest;
//}
