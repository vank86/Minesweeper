//
// Created by Ivan on 09/03/2023.
//

#include "MinesweeperBoard.h"
#include <iostream>
#include <algorithm>

MinesweeperBoard::MinesweeperBoard()
{
// git check
}


MinesweeperBoard::MinesweeperBoard(int heightInput1, int widthInput, GameMode mode)
        : height(heightInput1), width(widthInput)
{
    board.resize(height);
    for (int i = 0; i < height; i++)
        board[i].resize(width);

    if (mode == DEBUG) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (i == j || i == 0 || (j == 0 && i % 2 == 0))
                    board[i][j].hasMine = true;
                board[i][j].hasFlag = false;
                board[i][j].isRevealed = false;

            }
        }
    }
    if (mode == EASY) {
        int easyAmountOfMines;
        if ((height * width) % 10 == 0){
            easyAmountOfMines = static_cast<int>(height * width * 0.1);
        } else {
            easyAmountOfMines = static_cast<int>(height * width * 0.1) + 1;
        }
        srand(time(nullptr));
        for (int mines = 0; mines < easyAmountOfMines; mines++)
            board[rand()%height][rand()%width].hasMine = true;
    }
    if (mode == NORMAL) {
        int easyAmountOfMines = 0;
        if ((height * width) % 5 == 0){
            easyAmountOfMines = static_cast<int>(height * width * 0.2);
        } else {
            easyAmountOfMines = static_cast<int>(height * width * 0.2) + 1;
        }

        srand(time(nullptr));
        for (int mines = 0; mines < easyAmountOfMines; mines++)
            board[rand()%height][rand()%width].hasMine = true;
    }

    if (mode == HARD) {
        int easyAmountOfMines;
        if ((height * width) % 5 == 0){
            easyAmountOfMines = height * width * 0.2;
        } else {
            easyAmountOfMines = height * width * 0.2 + 1;
        }
        srand(time(nullptr));
        for (int mines = 0; mines < easyAmountOfMines; mines++)
            board[rand()%height][rand()%width].hasMine = true;
    }
}

void MinesweeperBoard::debug_display() const
{
    for (int i = 0; i < board.size(); i++) {
        cout << i + 1 << ". ";
        cout  << "[";
        for (auto j : board[i]) {
            cout << "[";
            if (!j.hasMine)
                cout << ".";
            else
                cout << "M";
            if (!j.isRevealed)
                cout << ".";
            else
                cout << "o";
            if(!j.hasFlag)
                cout << ".";
            else
                cout << "f";
            cout << "]";
        }
        cout << "]\n";
    }
}