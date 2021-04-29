#include <string>
#include <vector>
#include <iostream>

#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

class Board
{

public:
    int x_layer = 0b000000000;
    int o_layer = 0b000000000;

    char is_ended();
    void printBoard();
    void clearCell(int index);
    std::vector<int> getFreeCells();
    void setCell(char layer, int index);
};

#endif // BOARD_H_INCLUDED
