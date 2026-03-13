#include "logo.h"
#include <SFML/Graphics.hpp>

enum dir {UP, DOWN, LEFT, RIGHT};

class SnakeUnit {
private:
  dir direction;
  SnakeUnit* next;
public:
  SnakeUnit(dir d, SnakeUnit* n): next(n), direction(d) {}
  SnakeUnit(dir d): direction(d), next(nullptr) {}
  SnakeUnit(): direction(dir::UP), next(nullptr) {}
  unsigned length(SnakeUnit* head) {
    unsigned length = 0;
    while (head) {
      length += 1;
      head = head->next;
    }
    return length;
  };
  void extend(SnakeUnit* tail) {
    tail->next = new SnakeUnit;
    tail->next->next = nullptr;
    tail->next->direction = tail->direction;
  }
};

int main() {
  // Spare me the complexity and just keep the window the same size
  sf::RenderWindow window(sf::VideoMode({800, 600}), "Snake", sf::Style::Close);
  window.setIcon(sf::Image({LOGO_WIDTH, LOGO_HEIGHT}, logo));

  constexpr float borderWidth{50};

  auto worldBorder = window.getSize();

  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      } else if (event->is<sf::Event::Resized>()) {
        worldBorder = window.getSize();
      }
    }
    sf::RectangleShape playingArea({(float)worldBorder.x - borderWidth,
                                    (float)worldBorder.y - borderWidth});
    playingArea.setFillColor(sf::Color::Blue);
    playingArea.setPosition({borderWidth / 2, borderWidth / 2});

    window.clear(sf::Color::Cyan);

    window.draw(playingArea);

    window.display();
  }
  return 0;
}
