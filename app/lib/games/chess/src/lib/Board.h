#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <vector>

#include "Move.h"
#include "Color.h"
#include "Figure.h"
#include "Cell.h"


class Board {
private:
    std::vector<Cell> board;
    std::vector<Figure> whiteFigures, blackFigures;
public:
    explicit Board();

    explicit Board(std::vector<Cell> board);

    Cell &getCell(unsigned int idx);

    void applyMove(Move move);
};


#endif //CHESS_BOARD_H
