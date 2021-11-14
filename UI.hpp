#include <SFML/Graphics.hpp>

class UI: public sf::Drawable {
private:
    int bounces=0;
    int fps=0;
    sf::Text fpsText;
    sf::Text bounceText;
    //virtual void draw(sf::RenderTarget& target, sf::RenderStates states);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(fpsText, states);
        target.draw(bounceText, states);
    }
    sf::Font font;
public:
    UI(){
        font.loadFromFile("assets/JetBrainsMono.ttf");
        fpsText.setString("FPS: 0");
        fpsText.setFont(font);
        fpsText.setCharacterSize(22);
        fpsText.setFillColor(sf::Color::White);
        bounceText.setString("BOUNCES: 0");
        bounceText.setFont(font);
        bounceText.setCharacterSize(22);
        bounceText.setFillColor(sf::Color::White);
    };
    virtual ~UI(){};
    void update(int FPS, bool bounced, sf::Vector2u winSize) {
        fpsText.setPosition(winSize.x/2-fpsText.getLocalBounds().width/2, 0);
        bounceText.setPosition(winSize.x/2-bounceText.getLocalBounds().width/2, fpsText.getLocalBounds().height*1.2);
        if (bounced)
            bounces++;
        std::string temp = "FPS: ";
        temp.append(std::to_string(FPS));
        fpsText.setString(temp);
        temp = "BOUNCES: ";
        temp.append(std::to_string(bounces));
        bounceText.setString(temp);
    }
};