#include "Ball.hpp"
#include "Player.hpp"
#include "UI.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Game : public sf::RenderWindow {
private:
  int fps = 0;
  float deltaTime;
  sf::Clock dtClock;
  sf::Clock fpsClock;
  Player player1;
  Player player2;
  Ball ball;
  sf::Music backgroundMusic;
  UI ui{};

public:
  Game();
  ~Game() = default;
  void run();
  void render();
  void updateDT();
  void restart();
  void handleInput();
};
