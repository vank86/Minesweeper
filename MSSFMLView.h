//
// Created by Ivan on 05/04/2023.
//

#ifndef MINESWEEPER_1_MSSFMLVIEW_H
#define MINESWEEPER_1_MSSFMLVIEW_H

#include <SFML/Graphics.hpp>
#include "MinesweeperBoard.h"

class MSSFMLView {
private:
    MinesweeperBoard &board;
    sf::Font font;
    sf::Texture texture;
    int spriteRect = 90;
public:
    MSSFMLView(MinesweeperBoard &b);
    void draw(sf::RenderWindow &window);

};


#endif //MINESWEEPER_1_MSSFMLVIEW_H
