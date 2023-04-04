#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include <SFML/Graphics.hpp>

//git connection check

int main() {
    srand(time(nullptr));
    MinesweeperBoard board(6,7, EASY);
    board.debug_display();
    MSBoardTextView view (board);
//    view.display();
    board.revealField(1,3);
    cout << '\n';
    board.toggleFlag(2,2);
    view.display();
    MSTextController ctrl ( board, view );

//    ctrl.play();


/*------------SFML-----------*/

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window", sf::Style::Default);

    sf::CircleShape shape(20.f, 300);

    // set the shape color to green
    shape.setFillColor(sf::Color(100, 250, 50));

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::White);

        // draw everything here...
        shape.setPosition(10, 10);
        window.draw(shape);

        shape.setPosition(100, 100);
        window.draw(shape);

        // end the current frame
        window.display();
    }

//    std::cout << "\n\n\n";
//    MinesweeperBoard b(5,7, HARD);
//    b.debug_display();
}
