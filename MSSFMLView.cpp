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
// Create a text which uses our font
                font.loadFromFile("../arial.ttf");
                switch (board.countMines(i,j)) {
                    case 1:
                    {
                        sf::Text text("1", font, 25);
                        text.setPosition(static_cast<float>(i)*50.f + 15.f, static_cast<float>(j)*50.f + 8.f);
                        window.draw(text);
                        break;
                    };
                    case 2: {
                        sf::Text text("2", font, 25);
                        text.setPosition(static_cast<float>(i)*50.f + 15.f, static_cast<float>(j)*50.f + 8.f);
                        window.draw(text);
                        break;
                    };
                    case 3: {
                        sf::Text text("3", font, 25);
                        text.setPosition(static_cast<float>(i)*50.f + 15.f, static_cast<float>(j)*50.f + 8.f);
                        window.draw(text);
                        break;
                    };
                    case 4: {
                        sf::Text text("4", font, 25);
                        text.setPosition(static_cast<float>(i)*50.f + 15.f, static_cast<float>(j)*50.f + 8.f);
                        window.draw(text);
                        break;
                    } ;
                    case 5: {
                        sf::Text text("5", font, 25);
                        text.setPosition(static_cast<float>(i)*50.f + 15.f, static_cast<float>(j)*50.f + 8.f);
                        window.draw(text);
                        break;
                    };
                    case 6: {
                        sf::Text text("6", font, 25);
                        text.setPosition(static_cast<float>(i)*50.f + 15.f, static_cast<float>(j)*50.f + 8.f);
                        window.draw(text);
                        break;
                    };
                    case 7: {
                        sf::Text text("7", font, 25);
                        text.setPosition(static_cast<float>(i)*50.f + 15.f, static_cast<float>(j)*50.f + 8.f);
                        window.draw(text);
                        break;
                    };
                    case 8: {
                        sf::Text text("8", font, 25);
                        text.setPosition(static_cast<float>(i)*50.f + 15.f, static_cast<float>(j)*50.f + 8.f);
                        window.draw(text);
                        break;
                    };

                }

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
        }
    }
}