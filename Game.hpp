#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

class GameField;
class Game
{
private:
    GameField * field;
public:
    Game();
    void game();
};

#endif // GAME_HPP_INCLUDED
