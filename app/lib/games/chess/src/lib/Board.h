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

    void setFigures();

    void setPawns();

    void setRooks();

    void setKnights();

    void setBishops();

    void setQueens();

    void setKings();

public:
    Board();

    void build();

    Cell &getCell(unsigned int idx);

    void applyMove(Move move);

    Figure getKing(Color color);

    std::vector<Figure> *getFigures(Color color);
};


#endif //CHESS_BOARD_H
