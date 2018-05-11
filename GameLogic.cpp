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



//void GameLogic::computerPlayer()
//{
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

//}

