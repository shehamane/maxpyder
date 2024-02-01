#include "Board.h"

Board::Board() : board(std::vector<Cell>(64, Cell())), whiteFigures(std::vector<Figure>()),
                 blackFigures(std::vector<Figure>()) {
    whiteFigures.reserve(16);
    blackFigures.reserve(16);
}

void Board::setFigures() {
    for (int i = 0; i < 8; ++i) {
        whiteFigures.emplace_back(White, Pawn);
        blackFigures.emplace_back(Black, Pawn);
    }

    whiteFigures.emplace_back(White, Bishop);
    whiteFigures.emplace_back(White, Bishop);
    blackFigures.emplace_back(Black, Bishop);
    blackFigures.emplace_back(Black, Bishop);

    whiteFigures.emplace_back(White, Knight);
    whiteFigures.emplace_back(White, Knight);
    blackFigures.emplace_back(Black, Knight);
    blackFigures.emplace_back(Black, Knight);

    whiteFigures.emplace_back(White, Rook);
    whiteFigures.emplace_back(White, Rook);
    blackFigures.emplace_back(Black, Rook);
    blackFigures.emplace_back(Black, Rook);


    whiteFigures.emplace_back(White, Queen);
    blackFigures.emplace_back(Black, Queen);

    whiteFigures.emplace_back(White, King);
    blackFigures.emplace_back(Black, King);
}


void Board::setPawns() {
    for (unsigned int i = 8; i < 16; ++i) {
        board[i].figure = &whiteFigures[i - 8];
    }

    for (unsigned int i = 48; i < 56; ++i) {
        board[i].figure = &blackFigures[i - 48];
    }
}

void Board::setBishops() {
    board[2].figure = &whiteFigures[8];
    board[5].figure = &whiteFigures[9];
    board[58].figure = &blackFigures[8];
    board[61].figure = &blackFigures[9];
}

void Board::setKnights() {
    board[1].figure = &whiteFigures[10];
    board[6].figure = &whiteFigures[11];
    board[57].figure = &blackFigures[10];
    board[62].figure = &blackFigures[11];
}

void Board::setRooks() {
    board[0].figure = &whiteFigures[12];
    board[7].figure = &whiteFigures[13];
    board[56].figure = &blackFigures[12];
    board[63].figure = &blackFigures[13];
}

void Board::setQueens() {
    board[3].figure = &whiteFigures[14];
    board[59].figure = &blackFigures[14];
}

void Board::setKings() {
    board[4].figure = &whiteFigures[15];
    board[60].figure = &blackFigures[15];
}

void Board::build() {
    setFigures();
    setPawns();
    setRooks();
    setKnights();
    setBishops();
    setQueens();
    setKings();
}


Cell &Board::getCell(unsigned int idx) {
    return board[idx];
}

void Board::applyMove(Move move) {
    board[move.to].figure = board[move.from].figure;
    board[move.from].figure = nullptr;
}

Figure Board::getKing(Color color) {
    if (color == White) {
        return whiteFigures[15];
    }
    return blackFigures[15];
}

std::vector<Figure> *Board::getFigures(Color color) {
    if (color == White) {
        return &whiteFigures;
    }
    return &blackFigures;
}
