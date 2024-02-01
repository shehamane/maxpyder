#ifndef MAXPYDER_GAMECONTROLLER_H
#define MAXPYDER_GAMECONTROLLER_H

#pragma once

#include "Board.h"

#include <iostream>

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

    bool isCheck(Color color);

    void generateMask(int idx);

public:
    GameController();

    bool checkMove(Move move, Color color);

    void applyMove(Move move);

    void print();
};


#endif //MAXPYDER_GAMECONTROLLER_H
