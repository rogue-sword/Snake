#include "arena.h"
#include "logo.h"
#include <SFML/Graphics.hpp>

static const inline sf::Image Icon() {
  return sf::Image({LOGO_WIDTH, LOGO_HEIGHT}, logo);
}

// In this program it is assumed that even if you change the size of arena it is
// still of the same size as the window so, you don't need to center or resize
// it.'
int main() {
  sf::RenderWindow window(sf::VideoMode({800, 600}), "Snake");
  window.setIcon(Icon());

  sf::Texture _board(sf::Image({ARENA_WIDTH, ARENA_HEIGHT}, arena));
  sf::Sprite board(_board);

  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }

    window.clear(sf::Color::Cyan);

    window.draw(board);

    window.display();
  }
  return 0;
}
