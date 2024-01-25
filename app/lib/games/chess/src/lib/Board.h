#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <vector>

#include "Move.h"


enum Piece {
    Empty,
    Pawn,
    Rook,
    Knight,
    Bishop,
    Queen,
    King
};

enum Color {
    None,
    Black,
    White
};

struct Cell {
    Cell() : piece(Empty), color(None) {};

    Cell(Piece p, Color c) : piece(p), color(c) {};

    Piece piece;
    Color color;
};

class Board {
private:
    std::vector<Cell> board;

public:
    explicit Board();

    explicit Board(std::vector<Cell> board);

    void setCell(unsigned int idx, Cell cell);

    void applyMove(Move move);
};


#endif //CHESS_BOARD_H
