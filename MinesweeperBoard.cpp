//
// Created by Ivan on 09/03/2023.
//

#include "MinesweeperBoard.h"


//MinesweeperBoard::MinesweeperBoard()
//{
//
//
//}


MinesweeperBoard::MinesweeperBoard(int heightInput, int widthInput, GameMode mode)
        : height(heightInput), width(widthInput) {
    this->board.resize(height);
    for (int i = 0; i < height; i++)
        this->board[i].resize(width);
    this->State = RUNNING;
    amountOfMines = createMines(mode);
    this->minesRandomiser();
}

int MinesweeperBoard::createMines(const GameMode& mode) {
    amountOfMines = 0;
    switch (mode) {
        case EASY: {
            if ((height * width) % 10 == 0) {
                amountOfMines = static_cast<int>(height * width * 0.1);
            } else {
                amountOfMines = static_cast<int>(height * width * 0.1) + 1;
            }
        }
            break;
        case NORMAL: {
            if ((height * width) % 5 == 0) {
                amountOfMines = static_cast<int>(height * width * 0.2);
            } else {
                amountOfMines = static_cast<int>(height * width * 0.2) + 1;
            }
        }
            break;
        case HARD: {
            if ((height * width) % 3 == 0) {
                amountOfMines = static_cast<int>(height * width * 0.33);
            } else {
                amountOfMines = static_cast<int>(height * width * 0.33) + 1;
            }
        }
            break;
        case DEBUG:
        {
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
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
        if (!board[rand()%height][rand()%width].hasMine) {
            board[rand()%height][rand()%width].hasMine = true;
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
    /*
             Idea was taken from https://www.geeksforgeeks.org/cpp-implementation-minesweeper-game/

                -------------------------------------------------------------------
                |1.     row-1;col-1     |2.   row-1;col+0     |3.   row-1;col+1    |
                -------------------------------------------------------------------
                |4.     row+0;col-1     |     row  ;  col     |5.   row+0;col+1    |
                -------------------------------------------------------------------
                |6.     row+1;col-1     |7.   row+1;col+0     |8.   row+1;col+1    |
                -------------------------------------------------------------------
     */
    int countOfMines = 0;
    if (board[row-1][col-1].hasMine)     // 1.
        countOfMines++;
    if (board[row-1][col].hasMine)       // 2.
        countOfMines++;
    if (board[row-1][col+1].hasMine)     // 3.
        countOfMines++;
    if (board[row][col-1].hasMine)       // 4.
        countOfMines++;
    if (board[row][col+1].hasMine)       // 5.
        countOfMines++;
    if (board[row+1][col-1].hasMine)     // 6.
        countOfMines++;
    if (board[row+1][col].hasMine)       // 7.
        countOfMines++;
    if (board[row+1][col+1].hasMine)     // 8.
        countOfMines++;
    return countOfMines;

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

void MinesweeperBoard::revealField(int row, int col)
{
    if (!board[row][col].hasMine && !board[row][col].isRevealed)
        board[row][col].isRevealed = true;

//    first action: сделать проверку на открытые поля, если не было до этого -
//                  перемещаем мину;
//    if (board[row][col].hasMine && !board[row][col].isRevealed)
//    {
//        for (auto &i : board)
//            for (auto &j : i)
//                if(!j.isRevealed) {
//                    board[row][col].hasMine = false;
//
//                }
//    }
    if (board[row][col].hasMine && !board[row][col].isRevealed) {
        board[row][col].isRevealed = true;
    }
}

bool MinesweeperBoard::isRevealed(int row, int col) const
{
    if (board[row][col].isRevealed)
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
    int unrevealedCount = height * width;
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

char MinesweeperBoard::getFieldInfo(int row, int col) const
{
    if(row > height || col > width || row < 0 || col < 0)
        return '#';
    if(!board[row][col].isRevealed && board[row][col].hasFlag)
        return 'F';
    if(!board[row][col].isRevealed && !board[row][col].hasFlag)
        return '_';
    if(board[row][col].isRevealed && board[row][col].hasMine)
        return 'x';
    //  == 0 and > 0 cases are combined into 1 function instead of 2 separated ones
    if(board[row][col].isRevealed && MinesweeperBoard::countMines(row, col) >= 0) {
        switch (MinesweeperBoard::countMines(row, col)) {
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
