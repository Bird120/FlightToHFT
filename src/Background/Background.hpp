//
// Created by bird on 18/07/25.
//

#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Font.hpp>
#include <iostream>
#include "Utilities.hpp"
#include <SFML/Graphics.hpp>

class Background {

  private:
    sf::Texture texture;
    sf::Sprite sprite;
    float Xscreen = 0.0f;
    float Yposition = 0.0f;
    sf::View view;
  sf::Clock clock;
  float imageHeight;
  float imageWidth;

  public:
    Background(const std::filesystem::path &filename);
    sf::Sprite& getSprite();
    void screenMoving();
    void startMoving();
    sf::View& getView();

};
#endif //BACKGROUND_HPP
