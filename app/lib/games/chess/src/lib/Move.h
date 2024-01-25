#ifndef CHESS_MOVE_H
#define CHESS_MOVE_H

struct Move {
    Move(unsigned int from, unsigned int to) : from(from), to(to){};

    unsigned int from, to;
};

#endif //CHESS_MOVE_H
