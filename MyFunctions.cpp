#include "MyFunctions.hpp"
#include <sstream>
#include "graphics.hpp"

std::string int_to_string (int number)
{
    std::stringstream ss;
    ss<<number;
    std::string txt;
    ss>>txt;
    return txt;
}

void white()
{
    genv::gout << genv::color(255,250,250);
}
void black()
{
    genv::gout << genv::color(0,0,0);
}

void blue()
{
    genv::gout<< genv::color(106,90,205);
}
