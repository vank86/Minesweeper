
#ifndef MINESWEEPER_1_MSBOARDTEXTVIEW_H
#define MINESWEEPER_1_MSBOARDTEXTVIEW_H

#include <iostream>
#include <vector>

#include "MinesweeperBoard.h"

class MSBoardTextView {
private:
    MinesweeperBoard &board;
public:
    MSBoardTextView(MinesweeperBoard &b);
    void display();
};


#endif //MINESWEEPER_1_MSBOARDTEXTVIEW_H
