//
// Created by bird on 18/07/25.
//

#include "Background.hpp"
#include <SFML/Graphics/Rect.hpp>

#include <SFML/Graphics.hpp>

Background::Background(const std::filesystem::path &filename)
: texture(setTexture(filename)), sprite(texture)
{
    sprite.setTextureRect(sf::IntRect({0,0}, {1200, 800}));

    imageWidth = texture.getSize().x;
    imageHeight = texture.getSize().y;


}

sf::Sprite&  Background::getSprite()
{
    return sprite;
}
