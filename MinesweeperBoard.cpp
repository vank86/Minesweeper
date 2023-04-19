//
// Created by Ivan on 09/03/2023.
//

#include "MinesweeperBoard.h"


//MinesweeperBoard::MinesweeperBoard()
//{
//
//
//}


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
        }
            break;
        case NORMAL: {
            if ((width * height) % 5 == 0) {
                amountOfMines = static_cast<int>(width * height * 0.2);
            } else {
                amountOfMines = static_cast<int>(width * height * 0.2) + 1;
            }
        }
            break;
        case HARD: {
            if ((width * height) % 3 == 0) {
                amountOfMines = static_cast<int>(width * height * 0.33);
            } else {
                amountOfMines = static_cast<int>(width * height * 0.33) + 1;
            }
        }
            break;
        case DEBUG:
        {
            for (int i = 0; i < width; i++) {
                for (int j = 0; j < height; j++) {
                    if (i == j || i == 0 || (j == 0 && i % 2 == 0))
                        board[i][j].hasMine = true;
                }
            }
        } break;
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
    return height;
}

int MinesweeperBoard::getBoardHeight() const
{
    return width;
}

int MinesweeperBoard::getMineCount() const
{
    return amountOfMines;
}

int MinesweeperBoard::countMines(int col, int row) const
{
//    if (!board[col][row].isRevealed)
//        return -1;
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
//   ПРОБЛЕМА С ВЫХОДОМ ЗА ГРАНИЦУ ВЕКТОРА ПРИ ПРОВЕРКЕ МИН ВОКРУГ !!!!!

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

void MinesweeperBoard::toggleFlag(int col, int row)
{
    if (!board[col][row].isRevealed && !board[col][row].hasFlag)
        board[col][row].hasFlag = true;
    else if(!board[col][row].isRevealed && board[col][row].hasFlag)
        board[col][row].hasFlag = false;
}

// try to reveal the field at (row,col)
// Do nothing if any of the following is true
// - field was already revealed
// - either row or col is outside board
// - game is already finished
// - there is a flag on the field
//
// If the field was not revealed and there is no mine on it - reveal it
// If the field was not revealed and there is a mine on it:
// - if its the first player action - move mine to another location, reveal field (not in DEBUG mode!)
// - reveal it and finish game

void MinesweeperBoard::revealField(int col, int row)
{
    if (!board[col][row].hasMine && !board[col][row].isRevealed)
        board[col][row].isRevealed = true;

//    first action: сделать проверку на открытые поля, если не было до этого -
//                  перемещаем мину;
//    if (board[col][row].hasMine && !board[col][row].isRevealed)
//    {
//        for (auto &i : board)
//            for (auto &j : i)
//                if(!j.isRevealed) {
//                    board[col][row].hasMine = false;
//
//                }
//    }
    if (board[col][row].hasMine && !board[col][row].isRevealed) {
        board[col][row].isRevealed = true;
    }
}

bool MinesweeperBoard::isRevealed(int col, int row) const
{
    if (board[col][row].isRevealed)
        return true;
}

// return current game state:
// - FINISHED_LOSS - if the player revealed field with mine
// - FINISHED_WIN  - if the player won the game (all unrevealed fields have mines)
// - RUNNING       - if the game is not yet finished
//              ???

GameState MinesweeperBoard::getGameState() const
{
    for (auto &i : board)
        for (auto &j : i)
            if (j.hasMine && j.isRevealed)
                return FINISHED_LOSS;
    int unrevealedCount = width * height;
    for (auto &i : board)
        for (auto &j : i) {
            if (j.isRevealed)
                unrevealedCount--;
            if (unrevealedCount == amountOfMines)
                return FINISHED_WIN;
        }
    return RUNNING;
}




// if row or col is outside board                         - return '#' character                +++++
// if the field is not revealed and has a flag            - return 'F' character                +++++
// if the field is not revealed and does not have a flag  - return '_' (underscore) character   +++++
// if the field is revealed and has mine                  - return 'x' character                +++++
// if the field is revealed and has 0 mines around        - return ' ' (space) character        +++++
// if the field is revealed and has some mines around     - return '1' ... '8' (number of mines as a digit)

char MinesweeperBoard::getFieldInfo(int col, int row) const
{
    if(col > width || row > height || col < 0 || row < 0)
        return '#';
    if(!board[col][row].isRevealed && board[col][row].hasFlag)
        return 'F';
    if(!board[col][row].isRevealed && !board[col][row].hasFlag)
        return '_';
    if(board[col][row].isRevealed && board[col][row].hasMine)
        return 'x';
    //  == 0 and > 0 cases are combined into 1 function instead of 2 separated ones
    if(board[col][row].isRevealed && MinesweeperBoard::countMines(col, row) >= 0) {
        switch (MinesweeperBoard::countMines(col, row)) {
            case 0: return ' ';
            case 1: return '1';
            case 2: return '2';
            case 3: return '3';
            case 4: return '4';
            case 5: return '5';
            case 6: return '6';
            case 7: return '7';
            case 8: return '8';
            default: return '?';
        }
    }
}
float MinesweeperBoard::getSizeOfCell()
{
    return sizeOfCell = static_cast<float>(getBoardHeight()*9);
}