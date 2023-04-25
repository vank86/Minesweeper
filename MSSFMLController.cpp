//
// Created by Ivan on 12/04/2023.
//

#include "MSSFMLController.h"

MSSFMLController::MSSFMLController(MinesweeperBoard &board, MSSFMLView &view)
    : board(board), view(view)
{

}

void MSSFMLController::mouseControl(sf::Event &event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        int x = event.mouseButton.x / static_cast<int>(board.getSizeOfCell());
        int y = event.mouseButton.y / static_cast<int>(board.getSizeOfCell());
        if (event.mouseButton.button == sf::Mouse::Left && board.getGameState() == RUNNING && !board.hasFlag(x,y))
        {
            board.revealField(x,y);
        }
        else if (event.mouseButton.button == sf::Mouse::Right && board.getGameState() == RUNNING )
        {
            board.toggleFlag(x, y);

        }

    }
}