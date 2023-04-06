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
                rectangle.setPosition(i*50.f, j*50.f);
                window.draw(rectangle);
            }
            if(board.isRevealed(i,j) && board.countMines(i,j))
            {
// Create a text which uses our font
//                font.loadFromFile(arial.ttf);
                sf::Text text;
                text.setFont(font);
                text.setCharacterSize(30);
                text.setStyle(sf::Text::Regular);
                text.setString("Hello world");
                text.setCharacterSize(24); //
                text.setFillColor(sf::Color::Red);
                window.draw(text);

            }
            if(!board.isRevealed(i,j) && !board.hasFlag(i,j))
            {
                sf::RectangleShape emptyRectangle(sf::Vector2f(50.f, 50.f));
                emptyRectangle.setFillColor(sf::Color::Green);
                emptyRectangle.setOutlineThickness(5.f);
                emptyRectangle.setOutlineColor(sf::Color::White);
                emptyRectangle.setPosition(i*50.f, j*50.f);
                window.draw(emptyRectangle);
            }
        }
    }
}