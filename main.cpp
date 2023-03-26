#include "MinesweeperBoard.h"

//git connection check

int main() {
    srand(time(nullptr));
    MinesweeperBoard board(6,7, EASY);
    board.debug_display();


//    std::cout << "\n\n\n";
//    MinesweeperBoard b(5,7, HARD);
//    b.debug_display();
}
