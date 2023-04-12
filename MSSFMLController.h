//
// Created by Ivan on 12/04/2023.
//

#ifndef MINESWEEPER_1_MSSFMLCONTROLLER_H
#define MINESWEEPER_1_MSSFMLCONTROLLER_H
#include "MinesweeperBoard.h"
#include "MSSFMLView.h"


class MSSFMLController {
    MinesweeperBoard &board;
    MSSFMLView &view;
public:
    MSSFMLController(MinesweeperBoard &board, MSSFMLView &view);
    void mouseControl(sf::Event &event);
};


#endif //MINESWEEPER_1_MSSFMLCONTROLLER_H
