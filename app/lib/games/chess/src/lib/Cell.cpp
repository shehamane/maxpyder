#include "Cell.h"

Cell::Cell() : figure(nullptr) {}

Cell::Cell(Figure *p) : figure(p) {}

bool Cell::isEmpty() {
    return figure == nullptr;
}
