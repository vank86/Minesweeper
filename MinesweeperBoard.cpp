//
// Created by Ivan on 09/03/2023.
//

#include "MinesweeperBoard.h"
#include <iostream>

MinesweeperBoard::MinesweeperBoard()
{

}


MinesweeperBoard::MinesweeperBoard(int heightInput1, int widthInput, GameMode mode)
        : height(heightInput1), width(widthInput)
{
    if (mode == DEBUG){
        board.resize(height);
        for (int i = 0; i < height; i++)
            board[i].resize(width);
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (i == j || i == 1 || j % 2 == 0)
                    board[i][j].hasMine = true;
                board[i][j].hasFlag = false;
                board[i][j].isRevealed = false;

            }
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