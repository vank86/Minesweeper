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
    /*      PART 4        */
    // to think about DO NOTHING IF(*):
    int getBoardWidth() const;                  // OK
    int getBoardHeight() const;                 // OK
    int getMineCount() const;                   // OK
    int countMines(int row, int col) const;     // OK
    bool hasFlag(int row, int col) const;       // OK, MAY BE REBUILT
    void toggleFlag(int row, int col);          // OK       *
    void revealField(int row, int col);         // NOT OK   *
    bool isRevealed(int row, int col) const;    // OK
    GameState getGameState() const;             // NOT OK
    char getFieldInfo(int row, int col) const;  // OK

};


#endif //MINESWEEPER_1_MINESWEEPERBOARD_H
