#include <SFML/Graphics.hpp>
#include "Ball.hpp"
#include "Player.hpp"

class Game: public sf::RenderWindow {
private:
    int fps=0;
    float deltaTime;
    sf::Clock dtClock;
    sf::Clock fpsClock;
    Player player1{{20, 0}};
    Player player2{{1920-20-20, 0}};
    Ball ball{{100,100}};

public:
    Game();
    ~Game()= default;
    void run();
    void render();
    void updateDT();
};