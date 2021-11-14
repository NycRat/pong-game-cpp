#include <SFML/Graphics.hpp>

class Ball: public sf::Sprite {
private:
    sf::Texture texture;
    float speed = 600;
    sf::Vector2f direction = {0.4f,1};
public:
    Ball(sf::Vector2f);
    ~Ball() = default;
    void update(float dt);
    void collide(int side);
};