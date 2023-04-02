

#include "MSTextController.h"

MSTextController::MSTextController(MinesweeperBoard &b, MSBoardTextView &v) : board(b), view(v)
{

}

void MSTextController::play()
{
    while (board.getGameState() == RUNNING){
        int x, y;
        char move;
        cout << "Do you wanna toggle a flag or reveal a field? F/R" << endl;
        cin >> move;
        switch (move) {
            default: cout << "You entered a wrong answer!" << endl; break;
            case 'F':
            {
                cout << "Enter the coordinates you want to toggle(x and y)" << endl;
                cin >> x;
                cin >> y;
                board.toggleFlag(x, y);
                break;
            }
            case 'R':
            {
                cout << "Enter the coordinates you want to reveal(x and y)" << endl;
                cin >> x;
                cin >> y;
                board.revealField(x, y);
                break;
            }
        }
        view.display();
    }
}