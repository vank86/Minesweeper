#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "MSSFMLView.h"
#include "MSSFMLController.h"
#include <SFML/Graphics.hpp>

//git connection check

int main() {
    srand(time(nullptr));
//    MinesweeperBoard board(6,7, EASY);
//    board.debug_display();
//    MSBoardTextView view (board);
////    view.display();
//    board.revealField(1,3);
//    cout << '\n';
//    board.toggleFlag(2,2);
//    view.display();
//    MSTextController ctrl ( board, view );
//
//    ctrl.play();


/*------------SFML-----------*/
    sf::RenderWindow window(sf::VideoMode(900, 900), "Grafika w C++/SFML", sf::Style::Close);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(30);

    MinesweeperBoard board(10, 10, DEBUG);
    MSSFMLView view (board);  // przekazujemy przez referencję planszę jako argument konstruktora
    MSSFMLController controller(board,view);
    // symulujemy rozgrywkę
    board.toggleFlag(0,0);
    board.revealField(2,3);


    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        view.draw(window);
        window.display();
        controller.mouseControl(event);


    }
//    std::cout << "\n\n\n";
//    MinesweeperBoard b(5,7, HARD);
//    b.debug_display();
}
