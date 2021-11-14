#include "Player.hpp"

Player::Player(sf::Vector2f position) {
    texture.loadFromFile("assets/player.png");
    setTexture(texture);
    setTextureRect(sf::IntRect(0,0,20,300));
    setPosition(position);
}

void Player::update(double dt) {
}