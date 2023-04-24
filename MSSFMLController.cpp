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
            board.revealField(x / static_cast<int>(board.getSizeOfCell()), y / static_cast<int>(board.getSizeOfCell()));
        }
        else if (event.mouseButton.button == sf::Mouse::Right && board.getGameState() == RUNNING)
        {
            if (!board.hasFlag(x /static_cast<int>(board.getSizeOfCell()),y / static_cast<int>(board.getSizeOfCell()))){
                board.toggleFlag(x / static_cast<int>(board.getSizeOfCell()), y / static_cast<int>(board.getSizeOfCell()));
            } else {
                board.unToggleFlag(x / static_cast<int>(board.getSizeOfCell()), y / static_cast<int>(board.getSizeOfCell()));

            }
        }

    }
//    if(board.getGameState() == FINISHED_LOSS)
//     GAME_PAUSED
}