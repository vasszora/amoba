#include "GameLogic.hpp"
#include <iostream>
#include "time.h"
#include <cstdlib>

void GameLogic::switchPlayer()
{
    if(player==1)
    {
        player=2;
    }
    else
    {
        player=1;
    }
}

bool GameLogic::InARow(int howMany)
{
    int _size=field->fieldSize();
    int row=0;
    for(int i=0; i<_size; i++)
    {
        for (int j=0; j<_size-howMany; j++)
        {
            row=0;
            for(int k=0; k<howMany; k++)
            {
                if(field->state(i,j+k)==player)
                {
                    row++;
                }
                if(row<k)
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

bool GameLogic::InAColumn(int howMany)
{
    int _size=field->fieldSize();
    int column=0;
    for(int i=0; i<_size; i++)
    {
        for (int j=0; j<_size-howMany; j++)
        {
            column=0;
            for(int k=0; k<howMany; k++)
            {
                if(field->state(i+k,j)==player)
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

bool GameLogic::Across(int howMany)
{
    int _size=field->fieldSize();
    int across=0;
    //balról jobbra átlósan
    for(int i=0; i<_size-howMany; i++)
    {
        for (int j=0; j<_size-howMany; j++)
        {
            across=0;
            for(int k=0; k<howMany; k++)
            {
                if(field->state(i+k,j+k)==player)
                {
                    across++;
                }
                if(across<k) //a k ötig megy(ha a gyózelemhez vizsgáljuk), és együtt kell nõnie a keresztben lévõ x-ek számával. ha az x-ek száma kisebb bármikor, mint a k, már úgysem lehet 5
                {
                    continue;
                }
            }
            if (across==5)
            {
                return true;
            }
        }
    }
    //jobról balra átlósan
    for(int i=0; i<_size-howMany; i++)
    {
        for (int j=_size; j>howMany; j--)
        {
            across=0;
            for(int k=0; k<howMany; k++)
            {
                if(field->state(i+k,j-k)==player)
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

bool GameLogic::won()
{
    if(stepsMade<9) //ha még nem történt ennyi lépés összesen, akkor még senki nem gyõzhetett
    {
        return false;
    }
    if(Across(5) || InAColumn(5) || InARow(5))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void GameLogic::computerPlayer()
{
//
//    srand(time(0));
//    int _size=field->fieldSize();
//    for (int i=0; i<_size; i++)
//    {
//        for(int j=0; j<_size; j++)
//        {
//            if(field->state(i,j)==1)
//            {
//                do
//                {
//                    int r=1;
//                    for(int x=i-r; x<=i+r; x++)
//                    {
//                        for(int y=j-r;y<=y+r; y++)
//                        {
//                            if(field->state(x,y)==0)
//                            {
//                                coordinates={x,y};
//                            }
//                        }
//                    }
//
//
//                }
//                while(field->state(coordinates[0], coordinates[1])!=0);
//            }
//        }
//    }

}

