#include "GameController.h"
#include "BoardBuilder.h"

#include <cmath>

GameController::GameController() {
    BoardBuilder boardBuilder;
    board = boardBuilder.build();
}

void GameController::checkWhitePawnMove(int idx, std::vector<bool> &mask) {
    if (idx < 56 && board.getCell(idx + 8).isEmpty()) {
        mask[idx + 8] = true;
    }
    if (idx > 7 && idx < 16 && board.getCell(idx + 16).isEmpty()) {
        mask[idx + 16] = true;
    }
}

void GameController::checkWhitePawnAttack(int idx, std::vector<bool> &mask) {
    if (idx < 56 && idx % 8 && !board.getCell(idx + 7).isEmpty()) {
        mask[idx + 7] = true;
    }
    if (idx < 56 && idx % 8 != 7 && !board.getCell(idx + 9).isEmpty()) {
        mask[idx + 9] = true;
    }
}

void GameController::checkBlackPawnMove(int idx, std::vector<bool> &mask) {
    if (idx > 7 && board.getCell(idx - 8).isEmpty()) {
        mask[idx - 8] = true;
    }
    if (idx > 48 && idx < 56 && board.getCell(idx - 16).isEmpty()) {
        mask[idx - 16] = true;
    }
}

void GameController::checkBlackPawnAttack(int idx, std::vector<bool> &mask) {
    if (idx > 7 && idx % 8 && !board.getCell(idx - 7).isEmpty()) {
        mask[idx - 7] = true;
    }
    if (idx > 7 && idx % 8 != 7 && !board.getCell(idx - 9).isEmpty()) {
        mask[idx - 9] = true;
    }
}

void GameController::checkDiag(int idx, std::vector<bool> &mask, int mpr, int add) {
    bool isEmpty = false;

    int cur_idx = idx;
    do {
        cur_idx += (8 + add) * mpr;
        isEmpty = board.getCell(cur_idx).isEmpty();
        if (isEmpty) {
            mask[cur_idx] = true;
        }
    } while (!isEmpty && idx > 0 && idx < 64);
}

void GameController::checkKnight(int idx, std::vector<bool> &mask) {
    if (idx < 48 && idx % 8 != 7) {
        mask[idx + 17] = true;
    }
    if (idx < 48 && idx % 8) {
        mask[idx + 15] = true;
    }
    if (idx < 56 && idx % 8 < 6) {
        mask[idx + 10] = true;
    }
    if (idx < 56 && idx % 8 > 1) {
        mask[idx + 6] = true;
    }
    if (idx > 16 && idx % 8 != 7) {
        mask[idx - 17] = true;
    }
    if (idx > 16 && idx % 8) {
        mask[idx - 15] = true;
    }
    if (idx > 8 && idx % 8 < 6) {
        mask[idx - 10] = true;
    }
    if (idx > 8 && idx % 8 > 1) {
        mask[idx - 6] = true;
    }
}

void GameController::checkAxe(int idx, std::vector<bool> &mask, int mpr, int add) {
    bool isEmpty = false;

    int cur_idx = idx;
    do {
        cur_idx += (8 * mpr) + add;
        isEmpty = board.getCell(cur_idx).isEmpty();
        if (isEmpty) {
            mask[cur_idx] = true;
        }
    } while (!isEmpty && idx > 0 && idx < 64);
}

void GameController::checkKing(int idx, std::vector<bool> &mask) {
    if (idx % 8 != 7) {
        mask[idx + 1] = true;
        if (idx > 7) {
            mask[idx - 9] = true;
        }
        if (idx < 56) {
            mask[idx + 9] = true;
        }
    }
    if (idx % 8) {
        mask[idx - 1] = true;
        if (idx > 7) {
            mask[idx - 7] = true;
        }
        if (idx < 56) {
            mask[idx + 7] = true;
        }
    }
    if (idx > 7) {
        mask[idx - 8] = true;
    }
    if (idx < 56) {
        mask[idx + 8] = true;
    }
}

void GameController::generateMask(int idx) {
    Cell cell = board.getCell(idx);
    if (cell.isEmpty()) {
        return;
    }

    std::vector<bool> mask(64, false);
    if (cell.figure->piece == Pawn) {
        if (cell.figure->color == White) {
            checkWhitePawnMove(idx, mask);
            checkWhitePawnAttack(idx, mask);
        } else {
            checkBlackPawnMove(idx, mask);
            checkBlackPawnAttack(idx, mask);
        }
    } else if (cell.figure->piece == Bishop) {
        checkDiag(idx, mask, 1, 1);
        checkDiag(idx, mask, 1, -1);
        checkDiag(idx, mask, -1, 1);
        checkDiag(idx, mask, -1, -1);
    } else if (cell.figure->piece == Knight) {
        checkKnight(idx, mask);
    } else if (cell.figure->piece == Rook) {
        checkAxe(idx, mask, 1, 0);
        checkAxe(idx, mask, -1, 0);
        checkAxe(idx, mask, 0, 1);
        checkAxe(idx, mask, 0, -1);
    } else if (cell.figure->piece == Queen) {
        checkDiag(idx, mask, 1, 1);
        checkDiag(idx, mask, 1, -1);
        checkDiag(idx, mask, -1, 1);
        checkDiag(idx, mask, -1, -1);
        checkAxe(idx, mask, 1, 0);
        checkAxe(idx, mask, -1, 0);
        checkAxe(idx, mask, 0, 1);
        checkAxe(idx, mask, 0, -1);
    } else {
        checkKing(idx, mask);
    }
}


/*bool GameController::checkRule(Piece piece, Color color, Move move) {
    switch (piece) {
        case Pawn:
            return ((color == White &&
                     ((move.from > 8 && move.from < 16 && (move.to == move.from + 8 || move.to == move.from + 16))
                      || (move.to == move.from + 8))) ||
                    (color == Black &&
                     ((move.from > 48 && move.from < 56 && (move.to == move.from - 8 || move.to == move.from - 16))
                      || (move.to == move.from - 8))));
        case Bishop:
            return (abs((int) (move.from % 8) - (int) (move.to % 8)) ==
                    abs((int) (move.from / 8) - (int) (move.to / 8)));
        case Knight:
            return ((abs((int) (move.from % 8) - (int) (move.to % 8)) == 2 &&
                     abs((int) (move.from / 8) - (int) (move.to / 8)) == 1) ||
                    (abs((int) (move.from % 8) - (int) (move.to % 8)) == 1 &&
                     abs((int) (move.from / 8) - (int) (move.to / 8)) == 2));
        case Rook:
            return ((move.from % 8 == move.to % 8) || (move.from / 8 == move.to / 8));
        case Queen:
            return ((move.from % 8 == move.to % 8) || (move.from / 8 == move.to / 8) ||
                    (abs((int) (move.from % 8) - (int) (move.to % 8)) ==
                     abs((int) (move.from / 8) - (int) (move.to / 8))));
        case King:
            return (abs((int) (move.from % 8) - (int) (move.to % 8)) <= 1 &&
                    abs((int) (move.from / 8) - (int) (move.to / 8)) <= 1);
        case Empty:
            return false;
    }
}


bool GameController::checkMove(Move move, Color color) {
    if (!((board.getCell(move.from)->color == White && color == WhitePlayer)
          || (board.getCell(move.from)->color == Black && color == BlackPlayer))) {
        return false;
    }


}

*/
