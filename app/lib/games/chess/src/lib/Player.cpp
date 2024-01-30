#include "Player.h"

Player::Player(GameController *gc, Color c) : color(c), gameController(gc) {}

void Player::makeMove(Move move) {
    if (gameController->checkMove(move, color)){
        gameController->applyMove(move);
    }
}

