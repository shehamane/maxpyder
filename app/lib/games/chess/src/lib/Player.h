#ifndef CHESS_PLAYER_H
#define CHESS_PLAYER_H

#include "GameController.h"
#include "Move.h"

class Player {
private:
    GameController *gameController;
    Color color;

public:
    Player(GameController *gc, Color c);

    void makeMove(Move move);
};


#endif //CHESS_PLAYER_H
