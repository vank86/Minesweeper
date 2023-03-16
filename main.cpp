#include "MinesweeperBoard.h"

//git connection check

int main() {
    srand(time(nullptr));
    MinesweeperBoard a(5,7, EASY);
    a.debug_display();
//    std::cout << "\n\n\n";
//    MinesweeperBoard b(5,7, HARD);
//    b.debug_display();
}
