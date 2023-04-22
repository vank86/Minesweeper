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
        int x = event.mouseButton.x;
        int y = event.mouseButton.y;
        if (event.mouseButton.button == sf::Mouse::Left && board.getGameState() == RUNNING)
        {
            board.revealField(x / board.getSizeOfCell(), y / board.getSizeOfCell());
        }
        else if (event.mouseButton.button == sf::Mouse::Right && board.getGameState() == RUNNING)
        {
            board.toggleFlag(x / board.getSizeOfCell(), y / board.getSizeOfCell());
        }
    }
//    if(board.getGameState() == FINISHED_LOSS)
//     GAME_PAUSED
}