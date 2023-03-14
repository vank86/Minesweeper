//
// Created by Ivan on 09/03/2023.
//

#ifndef MINESWEEPER_1_MINESWEEPERBOARD_H
#define MINESWEEPER_1_MINESWEEPERBOARD_H
#include <vector>
#include <iostream>
#include <iostream>
#include <algorithm>

using std::cout;

enum GameMode
{
    DEBUG,
    EASY,
    NORMAL,
    HARD
};

struct Field{
    bool hasMine;
    bool isRevealed;
    bool hasFlag;
};

class MinesweeperBoard
{
private:
    int height;
    int width;
    std::vector<std::vector<Field>> board;

public:
    MinesweeperBoard();
    MinesweeperBoard(int heightInput1, int widthInput, GameMode  mode);
    void debug_display() const;
};


#endif //MINESWEEPER_1_MINESWEEPERBOARD_H
