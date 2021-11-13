#include "Player.hpp"

Player::Player() {
    texture.loadFromFile("assets/player.png");
    setTexture(texture);
    setTextureRect(sf::IntRect(0,0,150,150));
    setPosition(200,200);
}

void Player::update(double dt) {
    setPosition(getPosition().x+dt*100,getPosition().y+dt*100);
}