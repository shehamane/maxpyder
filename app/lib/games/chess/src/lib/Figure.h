#ifndef CHESS_FIGURE_H
#define CHESS_FIGURE_H

#include "Color.h"
#include "Piece.h"

#include <vector>

struct Figure {
    Color color;
    Piece piece;
    std::vector<bool> moveMask;

    explicit Figure(Color color, Piece piece);
};

#endif //CHESS_FIGURE_H
