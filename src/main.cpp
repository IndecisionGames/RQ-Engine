#include "RQ_Engine.h"
int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    b2Vec2 gravity(0.0f, -10.0f);
    b2World world(gravity);

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}
