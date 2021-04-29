#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "board.h"
#include "ai.h"

void process_user_move(Board& board)
{
    while (true)
    {
        int choice;
        std::cout << "Enter a move >> ";
        std::cin >> choice;

        std::vector<int> free_cells = board.getFreeCells();

        if (std::find(free_cells.begin(), free_cells.end(), choice - 1) != free_cells.end())
        {
            board.setCell('O', choice - 1);
            return;
        }
    }

}

int main()
{
    Board b1;

    while (b1.is_ended() == 'N')
    {
        b1.printBoard();
        process_user_move(b1);
        OptimalAI::move(b1, 'X');
        if (b1.is_ended() != 'N'){break;}
    }

    b1.printBoard();
    std::string result_msg;
    switch (b1.is_ended())
    {
        case 'X':
            result_msg = "AI Wins!";
            break;

        case 'O':
            result_msg = "User Wins!";
            break;

        case 'D':
            result_msg = "Draw!";
            break;

        default:
            result_msg = "Error Occurred";
    }

    std::cout << result_msg << std::endl;
    return 0;
}




