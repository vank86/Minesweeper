//
// Created by Ivan on 09/03/2023.
//

#include "MinesweeperBoard.h"


MinesweeperBoard::MinesweeperBoard()
{


}


MinesweeperBoard::MinesweeperBoard(int heightInput, int widthInput, GameMode mode)
        : height(heightInput), width(widthInput) {
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
        if ((height * width) % 10 == 0) {
            amountOfMines = static_cast<int>(height * width * 0.1);
        } else {
            amountOfMines = static_cast<int>(height * width * 0.1) + 1;
        }
        while (amountOfMines > 0) {
            int randomHeight = rand() % height;
            int randomWidth = rand() % width;
            if (!board[randomHeight][randomWidth].hasMine) {
                board[randomHeight][randomWidth].hasMine = true;
                amountOfMines--;
            } else
                continue;
        }
    }
    //            при помощи if else елс и мина уже есть не уменьшаем amountOfmines;

    if (mode == NORMAL) {
        if ((height * width) % 5 == 0) {
            amountOfMines = static_cast<int>(height * width * 0.2);
        } else {
            amountOfMines = static_cast<int>(height * width * 0.2) + 1;
        }

        while (amountOfMines > 0) {
            int randomHeight = rand() % height;
            int randomWidth = rand() % width;
            if (!board[randomHeight][randomWidth].hasMine) {
                board[randomHeight][randomWidth].hasMine = true;
                amountOfMines--;
            } else
                continue;
        }
    }

    if (mode == HARD) {
        if ((height * width) % 3 == 0) {
            amountOfMines = static_cast<int>(height * width * 0.33);
        } else {
            amountOfMines = static_cast<int>(height * width * 0.33) + 1;
        }
        while (amountOfMines > 0) {
            int randomHeight = rand() % height;
            int randomWidth = rand() % width;
            if (!board[randomHeight][randomWidth].hasMine) {
                board[randomHeight][randomWidth].hasMine = true;
                amountOfMines--;
            } else
                continue;
        }
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

int MinesweeperBoard::getBoardWidth() const
{
    return width;
}

int MinesweeperBoard::getBoardHeight() const
{
    return height;
}

int MinesweeperBoard::getMineCount() const
{
    return amountOfMines;
}

int MinesweeperBoard::countMines(int row, int col) const
{
    if (!board[row][col].isRevealed)
        return -1;
    if (row > height || col > width || row < 0 || col < 0)
        return -1;
// ??????????????
}

bool MinesweeperBoard::hasFlag(int row, int col) const
{
    if (board[row][col].hasFlag)
        return true;
    if((row > height || col > width || row < 0 || col < 0) || !board[row][col].hasFlag || board[row][col].isRevealed)
        return false;
}

void MinesweeperBoard::toggleFlag(int row, int col)
{
    if (!board[row][col].isRevealed)
        board[row][col].hasFlag = true;
}


