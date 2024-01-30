#include "Board.h"

Board::Board() {
    board = std::vector<Cell>(64);
}

Board::Board(std::vector<Cell> board) : board(std::move(board)) {}


Cell &Board::getCell(unsigned int idx) {
    return board[idx];
}

void Board::applyMove(Move move) {
    board[move.to].figure = board[move.from].figure;
    board[move.from].figure = nullptr;
}