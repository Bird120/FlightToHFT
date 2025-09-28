//
// Created by bird on 17/08/25.
//

#ifndef POPUP_HPP
#define POPUP_HPP

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include "Utilities.hpp"
#define WIDTH 500
#define HEIGHT 400

const sf::Color SELECTED_COLOR = sf::Color::Blue;
const sf::Color DEFAULT_COLOR = sf::Color::White;
constexpr int SECTIONS = 4;

class PopUp
{
  protected:
    const sf::Texture cadre;
    sf::Sprite sprite;
    sf::Font font;
    sf::Text Options[SECTIONS];
    std::string labels[SECTIONS];

  public:
    explicit PopUp(const std::string& questions);
    sf::Sprite& getSprite();
    void display(sf::RenderWindow& window);

};
#endif //POPUP_HPP
