#include "FiveInARowField.hpp"
#include "FiveInARowLogic.hpp"
#include "SimpleText.hpp"
#include "BlackOrWhiteSimpleText.hpp"
#include "NavigationButton.hpp"
#include <string>
#include <math.h>
#include <stdlib.h>
#include "functions.hpp"
FiveInARowField::FiveInARowField()
{
    using namespace genv;

    GameLogic * log = new FiveInARowLogic(this);
    logic=log;
    std::string openGame="Click here or press enter to play.";
    NavigationButton * open = new NavigationButton(max_X/2-gout.twidth(openGame)/2,max_Y/2,gout.twidth(openGame),20,openGame,[this](){this->newGame();},key_enter);
    navig.push_back(open);
    std::string endGame="Click here or press escape to exit.";
    NavigationButton * exit= new NavigationButton(max_X/2-gout.twidth(endGame)/2,3*max_Y/4,gout.twidth(endGame),20,endGame, [this](){this->exit();},key_escape);
    navig.push_back(exit);
    openingScreen();
}

void FiveInARowField::emptyField()
{
    using namespace genv;

    gout << move_to(0,0) << color(255,250,250) << box(max_X, max_Y);
    gout << color(106,90,205);
    for(int i=1; i<sizeOfField; i++) //a kockás háttér kirajzolása
    {
        gout << move_to(i*gridSize,0) << line(0,max_Y);
        gout << move_to(0,i*gridSize) << line(max_X, 0);
    }
    gout << refresh;
}

void FiveInARowField::eventLoop()
{
    using namespace genv;

    while(gin>>ev )
    {
        if(ev.type==ev_mouse && ev.button==btn_left && logic->validStep(whichLine(),whichRow()))
        {
            newField();
        }
        if(ev.type==ev_key) //most a navigáló widgetek csak a billentyû eseményekre reagálnak.
        {
            for(unsigned j=0; j<navig.size(); j++)
            {
                navig[j]->eventHandler(ev);
            }
        }
    }

}

void FiveInARowField::newField()
{
    if(logic->whichPlayer()==1)
    {
        Widget * w= new BlackOrWhiteSimpleText(whichLine()*gridSize+1, whichRow()*gridSize+1,gridSize-2,gridSize-2, "X", true);
        widgets.push_back(w);
    }
    else if(logic->whichPlayer()==2)
    {
        Widget * w= new BlackOrWhiteSimpleText(whichLine()*gridSize+1, whichRow()*gridSize+1,gridSize-2,gridSize-2, "0", true);
        widgets.push_back(w);
    }
    logic->stepMade(whichLine(),whichRow());
    if(logic->won())
    {
        endScreen();
    }
    logic->switchPlayer();
}

int FiveInARowField::whichLine()
{
    return floor(ev.pos_x/gridSize);
}

int FiveInARowField::whichRow()
{
    return floor(ev.pos_y/gridSize);
}

void FiveInARowField::openingScreen()
{
    using namespace genv;
    gout.open(max_X,max_Y);
    std::string game="FIVE IN A ROW";
    BlackOrWhiteSimpleText * gameName = new BlackOrWhiteSimpleText(max_X/2-gout.twidth(game)/2,max_Y/4,gout.twidth(game),20,game,false);

    for(unsigned i=0; i<navig.size(); i++)
    {
        navig[i]->draw();
    }
    gout << refresh;
    while(gin>>ev && !gameGoing)
    {
        for(unsigned i=0; i<navig.size(); i++)
        {
            navig[i]->eventHandler(ev);
        }
    }
    delete gameName;
    emptyField();
}

void FiveInARowField::endScreen()
{
    using namespace genv;
    gameGoing=false;
    int player=logic->whichPlayer();
    std::string who="Player " + int_to_string(player) + " wins!";
    gout << move_to(0,0) << color(0,0,0) << box(max_X,max_Y);
    BlackOrWhiteSimpleText *whoWon = new BlackOrWhiteSimpleText(max_X/2-gout.twidth(who)/2,max_Y/4,gout.twidth(who),20,who,false);

    for(unsigned i=0; i<navig.size(); i++)
    {
        navig[i]->draw();
    }
    gout << refresh;
    delete whoWon;

    while(gin>>ev && !gameGoing)
    {
        for(unsigned i=0; i<navig.size(); i++)
        {
            navig[i]->eventHandler(ev);
        }
    }
}

void FiveInARowField::exit() //exit gomb kezeli
{
    wantToExit=true;
    for(unsigned i=0; i<widgets.size(); i++)
    {
        delete widgets[i];
    }
    for(unsigned i=0; i<navig.size(); i++)
    {
        delete navig[i];
    }
    delete logic;
    delete this;
    std::exit(0); //ez igy jo??
}

void FiveInARowField::newGame() //open NavigationButton kezeli
{
    emptyField();
    //ha egy ujabb jatek kezdodik, kitorlom az elozo widgeteket
    for(unsigned i=0; i<widgets.size(); i++)
    {
        delete widgets[i];
    }
    eventLoop();
}
