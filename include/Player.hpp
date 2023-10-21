#include <SFML/Graphics.hpp>

class Player: public sf::Sprite {
private:
    sf::Texture texture;
public:
    Player(sf::Vector2f);
    ~Player() = default;
    void update(double dt);
};
