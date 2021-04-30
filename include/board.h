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
    void print_board();
    void clear_cell(int index);
    BoardLayer get_squashed_board();
    std::vector<int> get_free_cells();
    void set_cell(char layer, int index);
};

#endif // BOARD_H_INCLUDED
