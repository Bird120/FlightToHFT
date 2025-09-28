//
// Created by bird on 09/07/25.
//

#include "PlayerSprite.hpp"


PlayerSprite::PlayerSprite(const std::filesystem::path &filename)
: texture(setTexture(filename)), sprite(texture)
{
    setScaleSprite();
    initLoadImagePlayer();
}

void PlayerSprite::displayRightSprite(const Direction& dir)
{
    sprite.setTexture(texturesPlayer[dir]);
}



void PlayerSprite::initLoadImagePlayer()
{
    sf::Texture texture_player;

    /*texture_player.loadFromFile("/home/bird/CLionProjects/FlightToHFT++/assets/images/right.png");
    texturesPlayer[Direction::UP] = texture_player;*/
    if (!texture_player.loadFromFile("/home/bird/CLionProjects/FlightToHFT++/assets/images/right.png"))
        std::cerr << "Error :impossible to load right.png for UP" << std::endl;
    texturesPlayer[Direction::UP] = texture_player;

     if (!texture_player.loadFromFile("/home/bird/CLionProjects/FlightToHFT++/assets/images/right.png"))
         std::cerr << "Error :impossible to load right.png for DOWN" << std::endl;
    texturesPlayer[Direction::DOWN] = texture_player;

    if (!texture_player.loadFromFile("/home/bird/CLionProjects/FlightToHFT++/assets/images/left.png"))
        std::cerr << "Error :impossible to load right.png for LEFT" << std::endl;
    texturesPlayer[Direction::LEFT] = texture_player;

    if (!texture_player.loadFromFile("/home/bird/CLionProjects/FlightToHFT++/assets/images/right.png"))
        std::cerr << "Error :impossible to load right.png for RIGHT" << std::endl;
    texturesPlayer[Direction::RIGHT] = texture_player;

    sprite.setTexture(texturesPlayer[Direction::DOWN]);
}

void PlayerSprite::setterPosition(sf::RenderWindow &window, const bool& begin)
{
    //Remove
    (void)window;
    if (begin)
    {
        getSprite().setPosition(sf::Vector2f(this->Xposition, this->Yposition));
    }
    else
        getSprite().setPosition(sf::Vector2f(this->Xposition, this->Yposition));
}

void PlayerSprite::setScaleSprite()
{
    sprite.setOrigin({0, 0});
    sprite.setScale(sf::Vector2f(0.5f, 0.5f));
}



sf::Sprite&  PlayerSprite::getSprite()
{
  return sprite;
}

float PlayerSprite::getYPosition()
{
  return sprite.getPosition().y;

}
float PlayerSprite::getXPosition()
{
  return sprite.getPosition().x;

}


void PlayerSprite::setXPosition(float number)
{
    if (number== -200)
        Xposition = -200.0f;
    else
    {
        Xposition += number;
    }
}
void PlayerSprite::setYPosition(float number)
{
    Yposition += number;

}
