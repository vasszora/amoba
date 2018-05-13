#ifndef FIVEINAROWFIELD_HPP_INCLUDED
#define FIVEINAROWFIELD_HPP_INCLUDED

#include "GameField.hpp"

class FiveInARowField : public GameField
{
private:
    static const int sizeOfField=15;
    const int gridSize=max_X/sizeOfField;

public:
    FiveInARowField();
    void emptyField() const;
    void openingScreen();
    void newGame();
    void exit();
    void endScreen();
    void eventLoop();
    void newField();
    int whichLine();
    int whichRow();
    virtual ~ FiveInARowField() {};
};


#endif // FIVEINAROWFIELD_HPP_INCLUDED
