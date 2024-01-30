#ifndef CHESS_MOVE_H
#define CHESS_MOVE_H


struct Move {
public:
    unsigned int from, to;

    Move(unsigned int from, unsigned int to);
};


#endif //CHESS_MOVE_H
