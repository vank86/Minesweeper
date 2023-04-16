//
// Created by Ivan on 05/04/2023.
//

#include "MSSFMLView.h"
#include <SFML/Graphics.hpp>
MSSFMLView::MSSFMLView(MinesweeperBoard &b) : board(b)
{

}



void MSSFMLView::draw(sf::RenderWindow &window)
{
//    float sizeOfCell = 900*0.1;
    for (int i = 0; i < board.getBoardHeight(); i++) {
        for (int j = 0; j < board.getBoardWidth(); j++) {
            if (board.hasFlag(i,j))
            {
                sf::RectangleShape rectangle(sf::Vector2f(sizeOfCell, sizeOfCell));
                rectangle.setFillColor(sf::Color::Red);
                rectangle.setPosition(static_cast<float>(i)*sizeOfCell, static_cast<float>(j)*sizeOfCell);
                window.draw(rectangle);
            }
            if(board.isRevealed(i,j) && board.countMines(i,j))
            {
                font.loadFromFile("../arial.ttf");
                sf::Text text(std::to_string(board.countMines(i,j)), font, 40);
                text.setPosition(static_cast<float>(i*sizeOfCell + sizeOfCell*0.33), getSizeOfCell() + sizeOfCell*0.15);
                window.draw(text);
            }
            if(!board.isRevealed(i,j) && !board.hasFlag(i,j))
            {
                sf::RectangleShape emptyRectangle(sf::Vector2f(sizeOfCell, sizeOfCell));
                emptyRectangle.setFillColor(sf::Color::Green);
                emptyRectangle.setOutlineThickness(-3.f);
                emptyRectangle.setOutlineColor(sf::Color::White);
                emptyRectangle.setPosition(static_cast<float>(i)*sizeOfCell, static_cast<float>(j)*sizeOfCell);
                window.draw(emptyRectangle);
            }
            if(board.getGameState() == FINISHED_LOSS)
            {
                font.loadFromFile("../arial.ttf");
                sf::Text text("GAME OVER", font, 80);
                text.setPosition(static_cast<float>(board.getBoardWidth()) / 4 * 85.9, static_cast<float>(board.getBoardHeight()) / 3 * 85.9);
                window.draw(text);
            }
            if(board.getGameState() == FINISHED_WIN)
            {
                font.loadFromFile("../arial.ttf");
                sf::Text text("YOU WON!", font, 80);
                text.setPosition(static_cast<float>(board.getBoardWidth()) / 4 * 85.9, static_cast<float>(board.getBoardHeight()) / 3 * 85.9);
                window.draw(text);
            }
        }
    }
}

float MSSFMLView::getSizeOfCell()
{
    return sizeOfCell = static_cast<float>(board.getBoardHeight()*90);
}