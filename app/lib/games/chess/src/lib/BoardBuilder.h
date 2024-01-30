#ifndef CHESS_BOARDBUILDER_H
#define CHESS_BOARDBUILDER_H

#include "Board.h"

class BoardBuilder {
    std::vector<Cell> board;
    std::vector<Figure> blackFigures, whiteFigures;

    void setFigures();

    void setPawns();

    void setRooks();

    void setKnights();

    void setBishops();

    void setQueens();

    void setKings();
public:
    BoardBuilder();

    Board build();
};


#endif //CHESS_BOARDBUILDER_H
