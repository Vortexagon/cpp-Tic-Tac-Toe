#include "board.h"

#ifndef AI_H_INCLUDED
#define AI_H_INCLUDED

class RandomAI
{
public:
    static void move(Board& board);
};

class OptimalAI
{
public:
    static void move(Board& board);
    static float minimax(Board& board, bool maximising);
};

#endif // AI_H_INCLUDED
