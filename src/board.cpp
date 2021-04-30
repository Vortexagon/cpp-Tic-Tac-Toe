#include <string>
#include <iostream>
#include <vector>
#include <bitset>

#include "board.h"

char Board::is_ended()
{
    int win_masks[8] = {
        0b111000000, 0b000111000, 0b000000111,
        0b100100100, 0b010010010, 0b001001001,
        0b100010001, 0b001010100
    };

    for (BoardLayer layer : {x_layer, o_layer})
    {
        for (int mask : win_masks)
        {
            if ((layer.to_ulong() & mask) == mask)
            {
                return (layer == this->x_layer) ? 'X' : 'O';
            }
        }
    }

    BoardLayer squashed_board = this->getSquashedBoard();

    if (squashed_board.all())
    {
        return 'D';
    }

    return 'N';
};

void Board::printBoard()
{
    std::string horizontalSep = "+---+---+---+";

    char boardArray[9];

    for (int i = 0; i < 9; i++)
    {
        bool symbol_exists = false;

        for (BoardLayer layer: {x_layer, o_layer})
        {
            if (layer[i])
            {
                boardArray[i] = (layer == x_layer) ? 'X' : 'O';
                symbol_exists = true;
                break;
            }
        }

        if (!symbol_exists)
        {
            boardArray[i] = '1' + i;
        }
    }

    std::cout << horizontalSep << std::endl;
    for (int i = 0; i < 9; i += 3)
    {
        std::cout <<
         "| " << boardArray[i] <<
        " | " << boardArray[i + 1] <<
        " | " << boardArray[i + 2] <<
        " |"  << std::endl;

        std::cout << horizontalSep << std::endl;
    }
};

void Board::clearCell(int index)
{
    this->x_layer.reset(index);
    this->o_layer.reset(index);
}

std::vector<int> Board::getFreeCells()
{
    std::vector<int> free_cells;
    BoardLayer squashed_board = this->getSquashedBoard();

    for (int i = 0; i < 9; i++)
    {
        if (!squashed_board[i])
        {
            free_cells.push_back(i);
        }
    }

    return free_cells;
};

void Board::setCell(char layer, int index)
{
    BoardLayer& wanted_layer = layer == 'X' ? this->x_layer : this->o_layer;

    wanted_layer.set(index, true);
};

BoardLayer Board::getSquashedBoard()
{
    return this->x_layer | this->o_layer;
}
