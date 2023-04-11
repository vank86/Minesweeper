
#ifndef MINESWEEPER_1_MSTEXTCONTROLLER_H
#define MINESWEEPER_1_MSTEXTCONTROLLER_H

#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSSFMLView.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class MSTextController {
private:
    MinesweeperBoard &board;
    MSSFMLView &view;
public:
    MSTextController(MinesweeperBoard &b, MSSFMLView &v);
    void play();
};


#endif //MINESWEEPER_1_MSTEXTCONTROLLER_H
