#include <string>
#include <vector>
#include <iostream>
#include <bitset>

#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

typedef std::bitset<9> BoardLayer;
class Board
{

public:
    BoardLayer x_layer;
    BoardLayer o_layer;

    char is_ended();
    void printBoard();
    void clearCell(int index);
    BoardLayer getSquashedBoard();
    std::vector<int> getFreeCells();
    void setCell(char layer, int index);
};

#endif // BOARD_H_INCLUDED
