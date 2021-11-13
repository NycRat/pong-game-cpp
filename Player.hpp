#include <SFML/Graphics.hpp>

class Player: public sf::Sprite {
private:
    sf::Texture texture;
public:
    Player();
    ~Player() = default;
    void update(double dt);
};
