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
