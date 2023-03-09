//
// Created by Ivan on 09/03/2023.
//

#ifndef MINESWEEPER_1_MINESWEEPERBOARD_H
#define MINESWEEPER_1_MINESWEEPERBOARD_H
#include <vector>
#include <iostream>

using std::cout;
struct Field{
    bool hasMine;
    bool isRevealed;
    bool hasFlag;
};

class MinesweeperBoard
{
private:
    int width;
    int height;
    std::vector<std::vector<Field>> board;

public:
    MinesweeperBoard(int widthInput, int heightInput);
    void debug_display() const;
};


#endif //MINESWEEPER_1_MINESWEEPERBOARD_H
