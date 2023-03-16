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

enum GameMode   {DEBUG, EASY, NORMAL, HARD};
enum GameState  { RUNNING, FINISHED_WIN, FINISHED_LOSS };


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
    int amountOfMines;
    std::vector<std::vector<Field>> board;

public:
    MinesweeperBoard();
    MinesweeperBoard(int heightInput, int widthInput, GameMode  mode);
    void debug_display() const;
    int getBoardWidth() const;
    int getBoardHeight() const;
    int getMineCount() const;
    int countMines(int row, int col) const;
    bool hasFlag(int row, int col) const;
    void toggleFlag(int row, int col);


};


#endif //MINESWEEPER_1_MINESWEEPERBOARD_H
