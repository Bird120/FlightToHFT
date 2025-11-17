//
// Created by bird on 24/07/25.
//

#include "Coin.hpp"

Coin::Coin() : texture(setTexture("/home/bird/CLionProjects/FlightToHFT++/assets/images/coin2.png")), sprite(texture)
{

}


void Coin::draw(sf::RenderWindow& window) const
{
    window.draw(sprite);
}

sf::Sprite& Coin::getSprite()
{  return sprite;}

void Coin::setScale(float x, float y) {
    sprite.setScale({x, y});
}



void Coin::setPosition(float x, float y) {
    sprite.setPosition({x, y});
}