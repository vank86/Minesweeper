//
// Created by Ivan on 26/03/2023.
//

#include "MSBoardTextView.h"
#include <vector>

MSBoardTextView::MSBoardTextView(MinesweeperBoard &b) : board(b)
{
}

void MSBoardTextView::display()
{
    for (int i = 0; i < board.getBoardHeight(); i++) {
        cout << i + 1 << ". ";
        for (int j = 0; j < board.getBoardWidth(); j++) {
            if (board.hasFlag(i,j))
                cout << "f";
            if(board.isRevealed(i,j) && board.countMines(i,j))
                cout << board.countMines(i,j);
            if(!board.isRevealed(i,j) && !board.hasFlag(i,j))
                cout << "[ ]";
        }
        cout << '\n';
    }
}