#ifndef FIVEINAROWLOGIC_HPP_INCLUDED
#define FIVEINAROWLOGIC_HPP_INCLUDED

#include "GameLogic.hpp"

class FiveInARowLogic : public GameLogic
{
private:
    static const int sizeOfField=15;
    int stateOfField[sizeOfField][sizeOfField] ={};  //0-ra inicializalva
    // 0, 1-es es 2-es szammal jelzem majd, hogy milyen allapotban vannak a palya egyes elemei.
    //0-ures. 1-elso jatekose. 2-kettes jatekose.
    const int forTheWin = 5; //ennyi kell a gyozelemhez

public:
    FiveInARowLogic(GameField * _field) : GameLogic(_field) {};
    bool validStep(int i, int j);
    bool InARow(int howMany);
    bool InAColumn(int howMany);
    bool Across(int howMany);
    bool won();
    void changeState(int i, int j);
    int state(int i, int j) {return stateOfField[i][j];};
    void newGame();
    bool isFull();
};

#endif // FIVEINAROWLOGIC_HPP_INCLUDED
