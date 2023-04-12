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
    for (int i = 0; i < board.getBoardHeight(); i++) {
        for (int j = 0; j < board.getBoardWidth(); j++) {
            if (board.hasFlag(i,j))
            {
                sf::RectangleShape rectangle(sf::Vector2f(50.f, 50.f));
                rectangle.setFillColor(sf::Color::Red);
                rectangle.setPosition(static_cast<float>(i)*50.f, static_cast<float>(j)*50.f);
                window.draw(rectangle);
            }
            if(board.isRevealed(i,j) && board.countMines(i,j))
            {
                font.loadFromFile("../arial.ttf");
                sf::Text text(std::to_string(board.countMines(i,j)), font, 25);
                text.setPosition(static_cast<float>(i)*50.f + 15.f, static_cast<float>(j)*50.f + 8.f);
                window.draw(text);
            }
            if(!board.isRevealed(i,j) && !board.hasFlag(i,j))
            {
                sf::RectangleShape emptyRectangle(sf::Vector2f(50.f, 50.f));
                emptyRectangle.setFillColor(sf::Color::Green);
                emptyRectangle.setOutlineThickness(2.f);
                emptyRectangle.setOutlineColor(sf::Color::White);
                emptyRectangle.setPosition(static_cast<float>(i)*50.f, static_cast<float>(j)*50.f);
                window.draw(emptyRectangle);
            }
            if(board.getGameState() == FINISHED_LOSS)
            {
                font.loadFromFile("../arial.ttf");
                sf::Text text("GAME OVER", font, 60);
                text.setPosition(static_cast<float>(board.getBoardWidth()) / 3 * 50.f, static_cast<float>(board.getBoardHeight()) / 3 * 50.f);
                window.draw(text);


            }
        }
    }
}