#include "FiveInARowLogic.hpp"

void FiveInARowLogic::changeState(int i, int j)
{
    stateOfField[i][j]=player;
}

bool FiveInARowLogic::validStep(int i, int j)
{
    return state(i,j)==0;
}

void FiveInARowLogic::stepMade(int i, int j)
{
    stepsMade++;
    changeState(i,j);
}

bool FiveInARowLogic::InARow(int howMany)
{
    int row=0;
    for(int i=0; i<sizeOfField; i++)
    {
        for (int j=0; j<sizeOfField-howMany; j++)
        {
            row=0;
            for(int k=0; k<howMany; k++)
            {
                if(state(i,j+k)==player)
                {
                    row++;
                }
                if(row<k)//a k ötig megy, és együtt kell nõnie az egy oszlopban lévõ x-ek számával. ha az x-ek száma kisebb bármikor, mint a k, már úgysem lehet 5
                {
                    continue;
                }
            }
            if (row==howMany)
            {
                return true;
            }
        }
    }
    return false;
}

bool FiveInARowLogic::InAColumn(int howMany)
{
    int column=0;
    for(int i=0; i<sizeOfField; i++)
    {
        for (int j=0; j<sizeOfField-howMany; j++)
        {
            column=0;
            for(int k=0; k<howMany; k++)
            {
                if(state(i+k,j)==player)
                {
                    column++;
                }
                if(column<k) //a k ötig megy, és együtt kell nõnie az egy oszlopban lévõ x-ek számával. ha az x-ek száma kisebb bármikor, mint a k, már úgysem lehet 5
                {
                    continue;
                }
            }
            if (column==howMany)
            {
                return true;
            }
        }
    }
    return false;
}

bool FiveInARowLogic::Across(int howMany)
{
    int across=0;
    //balról jobbra átlósan
    for(int i=0; i<sizeOfField-howMany; i++)
    {
        for (int j=0; j<sizeOfField-howMany; j++)
        {
            across=0;
            for(int k=0; k<howMany; k++)
            {
                if(state(i+k,j+k)==player)
                {
                    across++;
                }
                if(across<k) //a k ötig megy(ha a gyózelemhez vizsgáljuk), és együtt kell nõnie a keresztben lévõ x-ek számával. ha az x-ek száma kisebb bármikor, mint a k, már úgysem lehet 5
                {
                    continue;
                }
            }
            if (across==howMany)
            {
                return true;
            }
        }
    }
    //jobról balra átlósan
    for(int i=0; i<sizeOfField-howMany; i++)
    {
        for (int j=sizeOfField; j>howMany; j--)
        {
            across=0;
            for(int k=0; k<howMany; k++)
            {
                if(state(i+k,j-k)==player)
                {
                    across++;
                }
                if(across<k)
                {
                    continue;
                }
            }
            if (across==howMany)
            {
                return true;
            }
        }
    }
    return false;
}

bool FiveInARowLogic::won()
{
    if(stepsMade<forTheWin*2-1) //ha még nem történt ennyi lépés összesen, akkor még senki nem gyõzhetett
    {
        return false;
    }
    if(Across(forTheWin) || InAColumn(forTheWin) || InARow(forTheWin))
    {
        newGame(); //lenullazom a state matrixot
        return true;
    }
    else
    {
        return false;
    }
}

bool FiveInARowLogic::gameOver()
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
    newGame(); //ha vegigerunk, akkor igaz, es vissza kell nullazni a matrixot
    return true;
}

void FiveInARowLogic::newGame()
{
    for(int i=0; i<sizeOfField; i++)
    {
        for(int j=0; j<sizeOfField; j++)
        {
            stateOfField[i][j]=0;
        }
    }
}
