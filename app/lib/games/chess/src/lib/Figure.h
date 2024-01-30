#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include "Color.h"

struct Piece{
    Color color;
    std::vector<bool> moveMask;

    explicit Piece(Color color);


};

#endif //CHESS_PIECE_H
