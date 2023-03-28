#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
//git connection check

int main() {
    srand(time(nullptr));
    MinesweeperBoard board(6,7, EASY);
    board.debug_display();
    MSBoardTextView view (board);
    view.display();
    board.revealField(1,3);
    cout << '\n';
    board.toggleFlag(2,2);
    view.display();


//    std::cout << "\n\n\n";
//    MinesweeperBoard b(5,7, HARD);
//    b.debug_display();
}
