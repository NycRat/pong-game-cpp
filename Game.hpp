#include <SFML/Graphics.hpp>
#include "Player.hpp"

class Game: public sf::RenderWindow {
private:
    int fps=0;
    double deltaTime;
    sf::Clock dtClock;
    sf::Clock fpsClock;
    Player player;

public:
    Game();
    ~Game()= default;
    void run();
    void render();
    void updateDT();
};