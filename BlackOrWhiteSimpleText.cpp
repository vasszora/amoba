#include "BlackOrWhiteSimpleText.hpp"
#include "functions.hpp"

void BlackOrWhiteSimpleText::draw()
{
    using namespace genv;

    if(whiteBackGround)
    {
       white();
       gout << move_to(x,y) << box(width,heigth) << move_to(x+5, y+13);
       black();
       gout << text(txt);
    }
    else
    {
       black();
       gout << move_to(x,y) << box(width,heigth) << move_to(x+5, y+13);
       white();
       gout << text(txt);
    }
    gout << refresh;
}
