#include <iostream>
#include <vector>

#include "board.h"
#include "ai.h"


void RandomAI::move(Board& board, char mark)
{
    board.setCell(mark, board.getFreeCells()[0]);
}

void OptimalAI::move(Board& board, char mark)
{
    int best_score = -999999;
    int best_index = 0;

    std::vector<int> free_cells = board.getFreeCells();

    for(const auto& value: free_cells) {

        board.setCell(mark, value);
        float score = OptimalAI::minimax(board, false, mark);
        board.clearCell(value);

        if (score > best_score)
        {
            best_score = score;
            best_index = value;
        }
    }
    board.setCell(mark, best_index);
}

float OptimalAI::minimax(Board& board, bool maximising, char ai_mark)
{
    char state = board.is_ended();
    if (state != 'N')
    {
        if (state == 'D'){return 0;}
        if (state == ai_mark){return 1;}
        else {return -1;}
    }

    float final_score;

    final_score = 999999 * (maximising ? -1 : 1);

    char opp_mark = ai_mark == 'X' ? 'O' : 'X';

    for (const auto& index: board.getFreeCells())
    {
        board.setCell(maximising ? ai_mark : opp_mark, index);
        float score = OptimalAI::minimax(board, !maximising, ai_mark);
        board.clearCell(index);

        if ((maximising && score > final_score) || (!maximising && score < final_score))
        {
            final_score = score;
        }
    }

    return final_score;

}
