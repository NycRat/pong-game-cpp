#include "Game.hpp"
#include <iostream>

Game::Game() {
    create({1500, 800}, "window", sf::Style::Default);
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
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        //     close();
        // }
        player.update(deltaTime);
        render();
    }
}

void Game::updateDT() {
    deltaTime = dtClock.restart().asSeconds();
}

void Game::render() {
    clear();
    draw(player);
    display();
}