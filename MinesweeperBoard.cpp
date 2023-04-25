
#include "MinesweeperBoard.h"


MinesweeperBoard::MinesweeperBoard(int widthInput, int heightInput, GameMode mode)
        : width(widthInput), height(heightInput) {
    this->board.resize(width);
    for (int i = 0; i < width; i++)
        this->board[i].resize(height);
    this->State = RUNNING;
    amountOfMines = createMines(mode);
    this->minesRandomiser();
}

int MinesweeperBoard::createMines(const GameMode& mode) {
    amountOfMines = 0;
    switch (mode) {
        case EASY: {
            if ((width * height) % 10 == 0) {
                amountOfMines = static_cast<int>(width * height * 0.1);
            } else {
                amountOfMines = static_cast<int>(width * height * 0.1) + 1;
            }
            break;
        }

        case NORMAL: {
            if ((width * height) % 5 == 0) {
                amountOfMines = static_cast<int>(width * height * 0.2);
            } else {
                amountOfMines = static_cast<int>(width * height * 0.2) + 1;
            }
            break;
        }

        case HARD: {
            if ((width * height) % 3 == 0) {
                amountOfMines = static_cast<int>(width * height * 0.33);
            } else {
                amountOfMines = static_cast<int>(width * height * 0.33) + 1;
            }
            break;
        }

        case DEBUG:
        {
            for (int i = 0; i < width; i++) {
                for (int j = 0; j < height; j++) {
                    if (i == j || i == 0 || (j == 0 && i % 2 == 0))
                        board[i][j].hasMine = true;
                }
            }
            break;
        }
    }
    return amountOfMines;
}

void MinesweeperBoard::minesRandomiser()
{
    int putMines = amountOfMines;
    while (putMines > 0) {
        if (!board[rand() % width][rand() % height].hasMine) {
            board[rand() % width][rand() % height].hasMine = true;
            putMines--;
        } else
            continue;
    }
}

int MinesweeperBoard::getBoardWidth() const
{
    return height;
}

int MinesweeperBoard::getBoardHeight() const
{
    return width;
}

float MinesweeperBoard::getSizeOfCell() const
{
    return static_cast<float>(getBoardHeight()*9);
}

int MinesweeperBoard::countMines(int col, int row) const
{
    if (col > width || row > height || col < 0 || row < 0)
        return -1;
    /*
             Idea was taken from https://www.geeksforgeeks.org/cpp-implementation-minesweeper-game/

                -------------------------------------------------------------------
                |1.     col-1;row-1     |2.   col-1;row+0     |3.   col-1;row+1    |
                -------------------------------------------------------------------
                |4.     col+0;row-1     |     col  ;  row     |5.   col+0;row+1    |
                -------------------------------------------------------------------
                |6.     col+1;row-1     |7.   col+1;row+0     |8.   col+1;row+1    |
                -------------------------------------------------------------------
     */

    int countOfMines = 0;
//    Free pos except corners and edges
    if (col != 0 && row != 0 && col != width - 1 && row != height - 1) {
        if (board[col - 1][row - 1].hasMine)     // 1.
            countOfMines++;
        if (board[col - 1][row].hasMine)       // 2.
            countOfMines++;
        if (board[col - 1][row + 1].hasMine)     // 3.
            countOfMines++;
        if (board[col][row - 1].hasMine)       // 4.
            countOfMines++;
        if (board[col][row + 1].hasMine)       // 5.
            countOfMines++;
        if (board[col + 1][row - 1].hasMine)     // 6.
            countOfMines++;
        if (board[col + 1][row].hasMine)       // 7.
            countOfMines++;
        if (board[col + 1][row + 1].hasMine)     // 8.
            countOfMines++;
    }
//    Top-Left corner
    if (col == 0 && row == 0)
    {
        if (board[col][row + 1].hasMine)       // 5.
            countOfMines++;
        if (board[col + 1][row].hasMine)       // 7.
            countOfMines++;
        if (board[col + 1][row + 1].hasMine)     // 8.
            countOfMines++;
    }
//    Top-Right corner
    if (col == 0 && row == height - 1)
    {
        if (board[col][row - 1].hasMine)       // 4.
            countOfMines++;
        if (board[col + 1][row - 1].hasMine)     // 6.
            countOfMines++;
        if (board[col + 1][row].hasMine)       // 7.
            countOfMines++;
    }
//    Bottom-Right corner
    if (col == width - 1 && row == height - 1)
    {
        if (board[col - 1][row - 1].hasMine)     // 1.
            countOfMines++;
        if (board[col - 1][row].hasMine)       // 2.
            countOfMines++;
        if (board[col][row - 1].hasMine)       // 4.
            countOfMines++;
    }
//    Bottom-Left corner
    if (col == width - 1 && row == 0)
    {
        if (board[col - 1][row].hasMine)       // 2.
            countOfMines++;
        if (board[col - 1][row + 1].hasMine)     // 3.
            countOfMines++;
        if (board[col][row + 1].hasMine)       // 5.
            countOfMines++;
    }

    //    Top edge
    if (col == 0 && row > 0 && row < height - 1)
    {
        if (board[col][row - 1].hasMine)       // 4.
            countOfMines++;
        if (board[col][row + 1].hasMine)       // 5.
            countOfMines++;
        if (board[col + 1][row - 1].hasMine)     // 6.
            countOfMines++;
        if (board[col + 1][row].hasMine)       // 7.
            countOfMines++;
        if (board[col + 1][row + 1].hasMine)     // 8.
            countOfMines++;
    }

    //    Bottom edge
    if (col == width - 1 && row > 0 && row < height - 1)
    {
        if (board[col - 1][row - 1].hasMine)     // 1.
            countOfMines++;
        if (board[col - 1][row].hasMine)       // 2.
            countOfMines++;
        if (board[col - 1][row + 1].hasMine)     // 3.
            countOfMines++;
        if (board[col][row - 1].hasMine)       // 4.
            countOfMines++;
        if (board[col][row + 1].hasMine)       // 5.
            countOfMines++;
    }

    //    Right edge
    if (row == height - 1 && col > 0 && col < width - 1)
    {
        if (board[col - 1][row - 1].hasMine)     // 1.
            countOfMines++;
        if (board[col - 1][row].hasMine)       // 2.
            countOfMines++;
        if (board[col][row - 1].hasMine)       // 4.
            countOfMines++;
        if (board[col + 1][row - 1].hasMine)     // 6.
            countOfMines++;
        if (board[col + 1][row].hasMine)       // 7.
            countOfMines++;
    }
    //    Left edge
    if (row == 0 && col > 0 && col < width - 1)
    {
        if (board[col - 1][row].hasMine)       // 2.
            countOfMines++;
        if (board[col - 1][row + 1].hasMine)     // 3.
            countOfMines++;
        if (board[col][row + 1].hasMine)       // 5.
            countOfMines++;
        if (board[col + 1][row].hasMine)       // 7.
            countOfMines++;
        if (board[col + 1][row + 1].hasMine)     // 8.
            countOfMines++;
    }
    return countOfMines;

}

bool MinesweeperBoard::hasFlag(int col, int row) const
{
    if (board[col][row].hasFlag)
        return true;
    if((col > width || row > height || col < 0 || row < 0) || !board[col][row].hasFlag || board[col][row].isRevealed)
        return false;
}

bool MinesweeperBoard::hasMine(int col, int row) const
{
    if (board[col][row].hasMine)
        return true;
    if((col > width || row > height || col < 0 || row < 0) || !board[col][row].hasMine || board[col][row].isRevealed)
        return false;
}

void MinesweeperBoard::toggleFlag(int col, int row)
{
    if (!board[col][row].isRevealed && !board[col][row].hasFlag)
        board[col][row].hasFlag = true;
    else if(!board[col][row].isRevealed && board[col][row].hasFlag)
        board[col][row].hasFlag = false;
}


void MinesweeperBoard::revealField(int col, int row)
{
    if (!board[col][row].isRevealed)
        board[col][row].isRevealed = true;
}

bool MinesweeperBoard::isRevealed(int col, int row) const
{
    if (board[col][row].isRevealed)
        return true;
}

GameState MinesweeperBoard::getGameState() const
{
    for (auto &i : board)
        for (auto &j : i)
            if (j.hasMine && j.isRevealed)
                return FINISHED_LOSS;
    return RUNNING;
}




