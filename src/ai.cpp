#include <iostream>
#include <vector>


#include "board.h"
#include "ai.h"


void RandomAI::move(Board& board)
{
    board.setCell('X', board.getFreeCells()[0]);
}

void OptimalAI::move(Board& board)
{
    int best_score = -999999;
    int best_index = 0;

    std::vector<int> free_cells = board.getFreeCells();

    for(const auto& value: free_cells) {

        board.setCell('X', value);
        float score = OptimalAI::minimax(board, false);
        board.clearCell(value);

        if (score > best_score)
        {
            best_score = score;
            best_index = value;
        }
    }
    board.setCell('X', best_index);
}

float OptimalAI::minimax(Board& board, bool maximising)
{
    char state = board.is_ended();
    if (state != 'N')
    {
        switch (state)
        {
        case 'X':
            return 1;
            break;

        case 'D':
            return 0;
            break;

        case 'O':
            return -1;
            break;

        default:
            return 0;
            break;
        }
    }

    float final_score;

    if (maximising)
    {
        final_score = -999999;

    } else
    {
        final_score = 999999;
    }

    for (const auto& index: board.getFreeCells())
    {

        board.setCell(maximising ? 'X' : 'O', index);
        float score = OptimalAI::minimax(board, !maximising);
        board.clearCell(index);

        if ((maximising && score > final_score) || (!maximising && score < final_score))
        {
            final_score = score;
        }
    }

    return final_score;

}
