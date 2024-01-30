#ifndef MAXPYDER_GAMECONTROLLER_H
#define MAXPYDER_GAMECONTROLLER_H

#pragma once

#include "Board.h"
#include "BoardBuilder.h"

class GameController {
private:
    Board board;

    void checkWhitePawnMove(int idx, std::vector<bool> &mask);

    void checkWhitePawnAttack(int idx, std::vector<bool> &mask);

    void checkBlackPawnMove(int idx, std::vector<bool> &mask);

    void checkBlackPawnAttack(int idx, std::vector<bool> &mask);

    void checkDiag(int idx, std::vector<bool> &mask, int mpr, int add);

    void checkAxe(int idx, std::vector<bool> &mask, int mpr, int add);

    void checkKnight(int idx, std::vector<bool> &mask);

    void checkKing(int idx, std::vector<bool> &mask);

    void checkCheck();

    void generateMask(int idx);

    static bool checkRule(Piece piece, Color color, Move move);

public:
    GameController();

    bool checkMove(Move move, Color color);

    bool applyMove(Move move);
};


#endif //MAXPYDER_GAMECONTROLLER_H
