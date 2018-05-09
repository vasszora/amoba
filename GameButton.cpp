#include "GameButton.hpp"
#include <iostream>

void GameButton::draw()
{
    using namespace genv;
    gout << move_to(x,y) ;
    gout<< color(255,250,250) ;
    gout<< box(width,heigth) ;
    gout<< move_to(x+3,y+gout.cdescent()+gout.cdescent()+5) ;
    gout<< color(0,0,0) << text(name);
}

void GameButton::changeName(std::string _newName)
{
    name=_newName;
}

void GameButton::eventHandler(genv::event ev)
{
    using namespace genv;
    if(logic->whichPlayer()==1 && isFocused(ev) )
    {
        changeName("X");
    }
    else if(logic->whichPlayer()==2 && isFocused(ev) )
    {
        changeName("O");
    }
    else
    {
        return;
    }
    draw();
    field->changeState(logic->whichPlayer(),whichLine(),whichColumn());
    logic->stepMade();
    if(logic->won())
    {
        field->endScreen();
    }
    logic->switchPlayer();
    gout << refresh;

}

int GameButton::whichLine()
{
    return y/field->gridWidth();
}

int GameButton::whichColumn()
{
    return x/field->gridWidth();
}
