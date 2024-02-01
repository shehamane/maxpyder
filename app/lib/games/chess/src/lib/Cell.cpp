#include "Cell.h"

#include <iostream>

Cell::Cell() : figure(nullptr) {}

Cell::Cell(Figure *p) : figure(p) {}

bool Cell::isEmpty() {
    return figure == nullptr;
}

void Cell::print() {
    if (isEmpty()) {
        std::cout << " ";
        return;
    }
    switch (figure->piece) {
        case Pawn:
            std::cout << "P";
            break;
        case Bishop:
            std::cout << "B";
            break;
        case Knight:
            std::cout << "K";
            break;
        case Rook:
            std::cout << "R";
            break;
        case Queen:
            std::cout << "Q";
            break;
        case King:
            std::cout << "X";
            break;
    }
}
