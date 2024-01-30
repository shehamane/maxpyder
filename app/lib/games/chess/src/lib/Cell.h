#ifndef CHESS_CELL_H
#define CHESS_CELL_H

#include "Figure.h"

struct Cell {
    Figure *figure;

    Cell();

    explicit Cell(Figure *p);

    bool isEmpty();
};


#endif //CHESS_CELL_H
