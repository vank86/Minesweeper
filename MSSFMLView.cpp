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
    if (! texture.loadFromFile("../images/minesweeper.png"))
    {
        abort();
    }
    sf::Sprite sprite(texture);
    for (int i = 0; i < board.getBoardHeight(); i++) {
        for (int j = 0; j < board.getBoardWidth(); j++) {
            if (board.isRevealed(i,j))
            {
//                sf::RectangleShape emptyRectangle(sf::Vector2f(board.getSizeOfCell(), board.getSizeOfCell()));
//                emptyRectangle.setFillColor(sf::Color::Black);
//                emptyRectangle.setOutlineThickness(-3.f);
//                emptyRectangle.setOutlineColor(sf::Color::White);
//                emptyRectangle.setPosition(static_cast<float>(i)*board.getSizeOfCell(), static_cast<float>(j)*board.getSizeOfCell());
//                window.draw(emptyRectangle);
                sprite.setTextureRect(sf::IntRect(0,0,board.getSizeOfCell(),board.getSizeOfCell()));
                sprite.setPosition(i *board.getSizeOfCell(), j * board.getSizeOfCell());
            }
            if (board.hasFlag(i,j))
            {
                sprite.setTextureRect(sf::IntRect(spriteRect*10,0,board.getSizeOfCell(),board.getSizeOfCell()));
                sprite.setPosition(i *board.getSizeOfCell(), j * board.getSizeOfCell());


            }
            if(board.isRevealed(i,j) && board.hasMine(i,j))
            {

                sprite.setTextureRect(sf::IntRect(spriteRect*9,0,board.getSizeOfCell(),board.getSizeOfCell()));
                sprite.setPosition(i *board.getSizeOfCell(), j * board.getSizeOfCell());

            }
            if(board.isRevealed(i,j) && board.countMines(i,j) && !board.hasMine(i,j))
            {
//                sf::RectangleShape emptyRectangle(sf::Vector2f(board.getSizeOfCell(), board.getSizeOfCell()));
//                emptyRectangle.setFillColor(sf::Color::Black);
//                emptyRectangle.setOutlineThickness(-3.f);
//                emptyRectangle.setOutlineColor(sf::Color::White);
//                emptyRectangle.setPosition(static_cast<float>(i)*board.getSizeOfCell(), static_cast<float>(j)*board.getSizeOfCell());
//                window.draw(emptyRectangle);
                font.loadFromFile("../font/arial.ttf");
                sf::Text text(std::to_string(board.countMines(i,j)), font, board.getSizeOfCell() / 2.25);
                text.setPosition(static_cast<float>(i*board.getSizeOfCell() + board.getSizeOfCell()*0.33), j*board.getSizeOfCell() + board.getSizeOfCell()*0.20);
                window.draw(text);
                sprite.setTextureRect(sf::IntRect(spriteRect*board.countMines(i,j),0,board.getSizeOfCell(),board.getSizeOfCell()));
                sprite.setPosition(i *board.getSizeOfCell(), j * board.getSizeOfCell());

            }
            if(!board.isRevealed(i,j) && !board.hasFlag(i,j))
            {
//                sf::RectangleShape emptyRectangle(sf::Vector2f(board.getSizeOfCell(), board.getSizeOfCell()));
//                emptyRectangle.setFillColor(sf::Color::Green);
//                emptyRectangle.setOutlineThickness(-3.f);
//                emptyRectangle.setOutlineColor(sf::Color::White);
//                emptyRectangle.setPosition(static_cast<float>(i)*board.getSizeOfCell(), static_cast<float>(j)*board.getSizeOfCell());
//                window.draw(emptyRectangle);
                sprite.setTextureRect(sf::IntRect(spriteRect * 11, 0, spriteRect, spriteRect));
                sprite.setPosition(i *board.getSizeOfCell(), j * board.getSizeOfCell());

            }
            if(board.getGameState() == FINISHED_LOSS)
            {
                font.loadFromFile("../font/arial.ttf");
                sf::Text text("GAME OVER", font, 80);
                text.setFillColor(sf::Color::Red);
                text.setPosition(board.getSizeOfCell() * 2.4, board.getSizeOfCell() * 3);
                window.draw(text);
            }
            if(board.getGameState() == FINISHED_WIN)
            {
                font.loadFromFile("../font/arial.ttf");
                sf::Text text("YOU WON!", font, 80);
                text.setFillColor(sf::Color::Red);
                text.setPosition(static_cast<float>(board.getBoardWidth()) / 4 * board.getSizeOfCell(), static_cast<float>(board.getBoardHeight()) / 3 * board.getSizeOfCell());
                window.draw(text);
            }
            window.draw(sprite);
        }
    }
}

