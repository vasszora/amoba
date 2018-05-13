#include "SimpleText.hpp"
#include "MyFunctions.hpp"
void SimpleText::draw() const
{
    using namespace genv;

    gout << move_to(x+3, y+17);
    white();
    gout << text(txt);
    gout << refresh;
}

