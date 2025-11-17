//
// Created by bird on 09/07/25.
//

#ifndef PLAYERSPRITE_HPP
#define PLAYERSPRITE_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Font.hpp>
#include <iostream>
#include <map>
#include "Direction.hpp"
#include "Utilities.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include "BackgroundManager.hpp"



class PlayerSprite {

  private:
    sf::Texture texture;
    sf::Sprite sprite;
    float Xposition = 100.0f;
    float Yposition = 500.0f;
    std::map<Direction, sf::Texture> texturesPlayer;
    void initLoadImagePlayer();
  std::map<Direction, sf::IntRect> spriteRects;

  public:

    //PlayerSprite(const std::filesystem::path &filename);
    PlayerSprite() = delete;
    PlayerSprite(const std::filesystem::path &filename);
    void setterPosition(sf::RenderWindow &window, const bool& begin);

    void displayRightSprite(const Direction& dir);
    void setScaleSprite();
    // afficher pour window draw main.cpp
    sf::Sprite& getSprite();
    float getYPosition();
    float getXPosition();
    void setXPosition(float number);
    void setYPosition(float number);
  //  void barsPositions(BackgroundManager& manager);


};
#endif //PLAYERSPRITE_HPP
