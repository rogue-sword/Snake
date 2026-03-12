#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Snake");
    window.setIcon(sf::Image("assets/logo.png"));

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear(sf::Color::Cyan);

        window.display();
    }
    return 0;
}
