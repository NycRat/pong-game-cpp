#include "Ball.hpp"
#include <iostream>
#include <random>

Ball::Ball (sf::Vector2f position) {
    texture.loadFromFile("assets/ball.png");
    setTexture(texture);
    setTextureRect(sf::IntRect(0,0,150,150));
    setPosition(position);
    setScale({0.5,0.5});
    srand(time(0));
}

void Ball::update(float dt) {
    move(direction*speed*dt);
}

void Ball::collide(int side) {
    float change = (float)((rand()%10)-5)/100;
    speed=500+rand()%300;
    if (side == 0) {
        direction.x = direction.x + change;
        direction.y = 1;
    } else if (side == 1) {
        direction.y = direction.y + change;
        direction.x = -1;
    } else if (side == 2) {
        direction.x = direction.x + change;
        direction.y = -1;
    } else if (side == 3) {
        direction.y = direction.y + change;
        direction.x = 1;
    }
}