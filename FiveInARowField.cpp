#include "FiveInARowField.hpp"
#include "FiveInARowLogic.hpp"
#include "SimpleText.hpp"
#include "BlackOrWhiteSimpleText.hpp"
#include "NavigationButton.hpp"
#include <string>
#include <math.h>
#include <stdlib.h>
#include "MyFunctions.hpp"
FiveInARowField::FiveInARowField()
{
    using namespace genv;

    GameLogic * log = new FiveInARowLogic();
    logic=log;
    //a navigalo gombokat letrehozom
    std::string openGame="Click here or press enter to play.";
    NavigationButton * open = new NavigationButton(max_X/2-gout.twidth(openGame)/2,max_Y/2,gout.twidth(openGame),20,openGame,[this](){this->newGame();},key_enter);
    navig.push_back(open);
    std::string endGame="Click here or press escape to exit.";
    NavigationButton * exit= new NavigationButton(max_X/2-gout.twidth(endGame)/2,3*max_Y/4,gout.twidth(endGame),20,endGame, [this](){this->exit();},key_escape);
    navig.push_back(exit);
    openingScreen();
}

void FiveInARowField::emptyField() const
{
    using namespace genv;
    white();
    gout << move_to(0,0) << box(max_X, max_Y);
    blue();
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

        //ha balkattintas tortenik egy olyan helyre, ahol ez helyes lepes, letrehozok egy uj simpletextet ott
        if(ev.type==ev_mouse && ev.button==btn_left)
        {
            if(logic->validStep(whichLine(),whichRow()))
            {
                newField();
            }
            else if(logic->gameOver()) //ha betelt a palya, megjelenik az endScreen
            {
                endScreen();
            }
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
    while(gin>>ev)
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
    std::string who;
    if(logic->won()) //ezt iratom ki, ha nyert valaki
    {
        int player=logic->whichPlayer();
        who="Player " + int_to_string(player) + " wins!";
    }
    else if(logic->gameOver()) //es ezt, hogyha betelt a palya, anelkul, hogy barki is nyert volna
    {
        who="Do you want to play again?";
    }
    black();
    gout << move_to(0,0) << box(max_X,max_Y);
    BlackOrWhiteSimpleText *whoWon = new BlackOrWhiteSimpleText(max_X/2-gout.twidth(who)/2,max_Y/4,gout.twidth(who),20,who,false);

    for(unsigned i=0; i<navig.size(); i++)
    {
        navig[i]->draw();
    }
    gout << refresh;
    delete whoWon;

    while(gin>>ev)
    {
        for(unsigned i=0; i<navig.size(); i++)
        {
            navig[i]->eventHandler(ev);
        }
    }
}

void FiveInARowField::exit() //exit gomb kezeli
{
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
    std::exit(0);
}

void FiveInARowField::newGame() //open NavigationButton kezeli
{
    emptyField();
    //ha egy ujabb jatek kezdodik, kitorlom az elozo jatekban letrehozott widgeteket
    for(unsigned i=0; i<widgets.size(); i++)
    {
        delete widgets[i];
    }
    eventLoop();
}
