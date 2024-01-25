#include "BoardBuilder.h"

BoardBuilder::BoardBuilder() : board(std::vector<Cell>(64)){}

void BoardBuilder::setPawns() {
    for (unsigned int i = 8; i < 16; ++i){
        board[i] = Cell(Pawn, White);
    }

    for (unsigned int i = 48; i < 56; ++i){
        board[i] = Cell(Pawn, Black);
    }
}

void BoardBuilder::setRooks() {
    board[2] = board[5] = Cell(Rook, White);
    board[58] = board[61] = Cell(Rook, Black);
}

void BoardBuilder::setKnights() {
    board[1] = board[6] = Cell(Knight, White);
    board[57] = board[62] = Cell(Knight, Black);
}

void BoardBuilder::setBishops() {
    board[0] = board[7] = Cell(Bishop, White);
    board[56] = board[63] = Cell(Bishop, Black);
}

void BoardBuilder::setQueens() {
    board[3] = Cell(Queen, White);
    board[59] = Cell(Queen, Black);
}

void BoardBuilder::setKings() {
    board[4] = Cell(King, White);
    board[60] = Cell(King, Black);
}

Board BoardBuilder::build() {
    setPawns();
    setRooks();
    setKnights();
    setBishops();
    setQueens();
    setKings();

    return Board(board);
}


