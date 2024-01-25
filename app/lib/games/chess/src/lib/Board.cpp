#include "Board.h"

void Board::applyMove(Move move) {
    board[move.to] = board[move.from];
    board[move.from] = Cell(Empty, None);
}

void Board::setCell(unsigned int idx, Cell cell) {
    board[idx] = cell;
}

Board::Board() {
    board = std::vector<Cell>(64);
}

Board::Board(std::vector<Cell> board) : board(std::move(board)) {}
