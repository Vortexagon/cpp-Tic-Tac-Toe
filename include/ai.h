#include "board.h"

#ifndef AI_H_INCLUDED
#define AI_H_INCLUDED

class RandomAI
{
public:
    static void move(Board& board, char mark);
};

class OptimalAI
{
public:
    static void move(Board& board, char mark);
    static float minimax(Board& board, bool maximising, char ai_mark);
};

#endif // AI_H_INCLUDED
