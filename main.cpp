#include "MinesweeperBoard.h"
#include "MSSFMLView.h"
#include "MSSFMLController.h"
#include <SFML/Graphics.hpp>



int main() {
    srand(time(nullptr));

/*------------SFML-----------*/
    sf::RenderWindow window(sf::VideoMode(900, 900), "Grafika w C++/SFML", sf::Style::Close);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(30);

    MinesweeperBoard board(10, 10, DEBUG);
    MSSFMLView view (board);
    MSSFMLController controller(board,view);

    while (window.isOpen())
    {
        sf::Event event;
        window.clear();
        view.draw(window);
        window.display();
        while (window.pollEvent(event))
        {
            controller.mouseControl(event);
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

}
