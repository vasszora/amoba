#ifndef BLACKORWHITESIMPLETEXT_HPP_INCLUDED
#define BLACKORWHITESIMPLETEXT_HPP_INCLUDED

#include "SimpleText.hpp"

class BlackOrWhiteSimpleText : public SimpleText
{
private:
    bool whiteBackGround;
public:
    BlackOrWhiteSimpleText(int _x, int _y, int _w, int _h, std::string _txt, bool white) : SimpleText(_x,_y,_w,_h,_txt), whiteBackGround(white) {draw();};
    void draw();

};
#endif // BLACKORWHITESIMPLETEXT_HPP_INCLUDED
