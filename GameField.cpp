#include "GameField.hpp"
#include "GameButton.hpp"
#include "NavigationButton.hpp"
GameField::GameField()
{
    using namespace genv;
    logic= new GameLogic(this);
    //ehelyett lehetne, hogy csak akkor jöjjenek létre ha gombnyomás történik és zajlik a játék
    for(int i=0; i<sizeOfField; i++)
    {
        for(int j=0; j<sizeOfField; j++)
        {
            Widget * w = new GameButton(j*gridSize+1, i*gridSize+1, gridSize-2, gridSize-2, "", logic, this);
            widgets.push_back(w);
        }
    }
    std::string gameName="FIVE IN A ROW";
    std::string openGame="Click here or press enter to play.";
    NavigationButton * open = new NavigationButton(max_X/2-gout.twidth(openGame)/2,max_Y/2,gout.twidth(openGame),20,openGame,[this]()
    {
        this->newGame();
    },key_enter);
    navig.push_back(open);
    std::string endGame="Click here or press escape to exit.";
    NavigationButton * exit= new NavigationButton(max_X/2-gout.twidth(endGame)/2,3*max_Y/4,gout.twidth(endGame),20,endGame, [this](){this->exit();},key_escape);
    navig.push_back(exit);
    std::string Won="YOU WON!";
    std::string Lost="YOU LOST. :(";
    names["game"]= new SimpleText(max_X/2-gout.twidth(gameName)/2,max_Y/4,gout.twidth(gameName),20,gameName);
//    names["open"]= new SimpleText(max_X/2-gout.twidth(openGame)/2,max_Y/2,gout.twidth(openGame),20,openGame);
//    names["end"]= new SimpleText();
//    names["restart"]= new SimpleText(max_X/2-gout.twidth(restartGame)/2,max_Y/2,gout.twidth(restartGame),20,restartGame);
    names["won"]= new SimpleText(max_X/2-gout.twidth(Won)/2,max_Y/4,gout.twidth(Won),20,Won);
    names["lost"]= new SimpleText(max_X/2-gout.twidth(Lost)/2,max_Y/4,gout.twidth(Lost),20,Lost);
    openingScreen();
}

void GameField::emptyField()
{
    gameGoing=true;
    using namespace genv;

    gout << move_to(0,0) << color(255,250,250) << box(max_X, max_Y);
    gout << color(106,90,205);
    for(int i=1; i<sizeOfField; i++)
    {
        gout << move_to(i*gridSize,0) << line(0,max_Y);
        gout << move_to(0,i*gridSize) << line(max_X, 0);
    }
    gout << refresh;
}

bool GameField::isFull()
{
    for (int i=0; i<sizeOfField; i++)
    {
        for (int j=0; j<sizeOfField; j++)
        {
            if(state(i,j)==0)
            {
                return false;
            }
        }
    }
    return true;
}

void GameField::eventLoop()
{
    using namespace genv;
    while(gin>>ev && !wantToExit)
    {
        for(unsigned i=0; i<widgets.size(); i++)
        {
            widgets[i]->eventHandler(ev);
        }
        if(ev.type==ev_key) //most a navigáló widgetek csak a billentyű eseményekre reagálnak.
        {
            for(unsigned j=0; j<navig.size(); j++)
            {
                navig[j]->eventHandler(ev);
            }
        }
    }
    endScreen();
    //exit();

}

void GameField::changeState(int player, int i, int j)
{
    if (state(i,j)==0)
    {
        stateOfField[i][j]=player;
    }
}

void GameField::openingScreen()
{
    using namespace genv;
    gout.open(max_X,max_Y);
//    gout << move_to(max_X/2-gout.twidth(gameName)/2,max_Y/4) << color(255,255,255) << text(gameName);
//    gout << move_to(max_X/2-gout.twidth(openGame)/2,max_Y/2) << text(openGame);
//    gout << move_to(max_X/2-gout.twidth(endGame)/2,3*max_Y/4) << text(endGame);
    names["game"]->draw();
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
    emptyField();
}

void GameField::endScreen()
{
    using namespace genv;
    gameGoing=false;
    gout << move_to(0,0) << color(0,0,0) << box(max_X,max_Y);
    if(logic->whichPlayer()==1)
    {
        names["won"]->draw();
    }
    else
    {
        names["lost"]->draw();
    }
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
}

void GameField::exit() //exit gomb kezeli
{
//    for(unsigned i=0; i<widgets.size(); i++)
//    {
//        delete widgets[i];
//    }
    delete logic;
    names.clear();
    delete this;
}

void GameField::newGame() //open NavigationButton kezeli
{
    emptyField();
    //a mátrixot lenullázom
    for(int i=0; i<sizeOfField; i++)
    {
        for(int j=0; j<sizeOfField; j++)
        {
            stateOfField[i][j]=0;
        }
    }
    eventLoop();
}
