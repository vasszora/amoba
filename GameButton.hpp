#ifndef GAMEBUTTON_HPP_INCLUDED
#define GAMEBUTTON_HPP_INCLUDED

#include "Button.hpp"
#include "GameLogic.hpp"
#include "GameField.hpp"
class GameLogic;
class GameField;

class GameButton : public Button
{
private:
    GameLogic * logic;
    GameField * field;
public:
    GameButton(int _x, int _y,int _w, int _h, std::string _name, GameLogic* _logic, GameField * _field) : Button(_x,_y,_w,_h,_name), logic(_logic), field(_field){};
    void changeName(std::string newName);
    void draw();
    void eventHandler(genv::event ev);
    int whichLine();
    int whichColumn();
};

#endif // GAMEBUTTON_HPP_INCLUDED
