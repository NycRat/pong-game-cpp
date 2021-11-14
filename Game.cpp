#include "Game.hpp"
#include <iostream>

Game::Game() {
    create({1920, 1080}, "window", sf::Style::Fullscreen);
}

void Game::run () {
    sf::Event ev;
    int frames=0;
    while (isOpen()) {
        frames++;
        updateDT();
        while (pollEvent(ev)) {
            if (ev.type == sf::Event::Closed) {
                close();
            }
            if (ev.key.code == sf::Keyboard::Escape) {
                close();
            }
        }
        if (fpsClock.getElapsedTime().asSeconds() >= 1) {
            fpsClock.restart();
            fps = frames;
            frames=0;
            std::cout << fps << std::endl;
        }
        if (ball.getPosition().x <= 0 || ball.getPosition().x+75 >= getSize().x) {
            // close();
        } else {
            if (ball.getPosition().y+75 >= getSize().y)
                ball.collide(2);
            else if (ball.getPosition().y <= 0)
                ball.collide(0);
            else if (ball.getPosition().x+75 >= player2.getPosition().x) {
                if (ball.getPosition().y-75/2 >= player2.getPosition().y) {
                    if (ball.getPosition().y-75/2 <= player2.getPosition().y+300)
                        ball.collide(1);
                }
            } else if (ball.getPosition().x <= player1.getPosition().x+20) {
                if (ball.getPosition().y-75/2 >= player1.getPosition().y) {
                    if (ball.getPosition().y-75/2 <= player1.getPosition().y+300)
                        ball.collide(3);
                }
            } 
        }
        ball.update(deltaTime);
        player1.update(deltaTime);
        player2.update(deltaTime);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            player1.move({0,-1000*deltaTime});
            if (player1.getPosition().y < 0)
                player1.setPosition({player1.getPosition().x, 0});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            player1.move({0,1000*deltaTime});
            if (player1.getPosition().y+player1.getLocalBounds().height > getSize().y)
                player1.setPosition({player1.getPosition().x, getSize().y-player1.getLocalBounds().height});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            player2.move({0,-1000*deltaTime});
            if (player2.getPosition().y < 0)
                player2.setPosition({player2.getPosition().x, 0});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            player2.move({0,1000*deltaTime});
            if (player2.getPosition().y+player2.getLocalBounds().height > getSize().y)
                player2.setPosition({player2.getPosition().x, getSize().y-player2.getLocalBounds().height});
        }
        render();
    }
}

void Game::updateDT() {
    deltaTime = dtClock.restart().asSeconds();
}

void Game::render() {
    clear();
    draw(ball);
    draw(player1);
    draw(player2);
    display();
}