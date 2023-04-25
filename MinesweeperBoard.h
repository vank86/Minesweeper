//
// Created by Ivan on 09/03/2023.
//

#ifndef MINESWEEPER_1_MINESWEEPERBOARD_H
#define MINESWEEPER_1_MINESWEEPERBOARD_H
#include <vector>
#include <iostream>
#include <iostream>
#include <algorithm>

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
    int width;
    int height;
    int amountOfMines;
    GameState State;
    std::vector<std::vector<Field>> board;


public:
    MinesweeperBoard(int widthInput, int heightInput, GameMode mode);
    int createMines(const GameMode& mode);
    void minesRandomiser();
    /*      PART 4        */
    // to think about DO NOTHING IF(*):
    int getBoardWidth() const;                  // OK
    int getBoardHeight() const;                 // OK
    int countMines(int col, int row) const;     // OK
    bool hasFlag(int col, int row) const;       // OK, MAY BE REBUILT
    bool hasMine(int col, int row) const;
    void toggleFlag(int col, int row);          // OK       *
    void revealField(int col, int row);         // NOT OK   *
    bool isRevealed(int col, int row) const;    // OK
    GameState getGameState() const;             // OK
    float getSizeOfCell() const;
};


#endif //MINESWEEPER_1_MINESWEEPERBOARD_H
