//
// Created by Ivan on 09/03/2023.
//

#include "MinesweeperBoard.h"
#include <iostream>

MinesweeperBoard::MinesweeperBoard(int widthInput, int heightInput) : width(widthInput), height(heightInput)
{
    board.resize(width);
    for (int i = 0; i < width; i++)
        board[i].resize(height);
    for (int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++) {
            board[i][j].hasMine = true;
            board[i][j].hasFlag = true;
            board[i][j].isRevealed = true;

        }
    }
}

void MinesweeperBoard::debug_display() const
{
    for (auto &i : board) {
        cout << "[";
        for (auto &j: i) {
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