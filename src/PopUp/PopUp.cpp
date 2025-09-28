//
// Created by bird on 17/08/25.
//

#include "PopUp.hpp"


PopUp::PopUp(const std::string& questions)
    : cadre(setTexture("/home/bird/CLionProjects/FlightToHFT++/assets/popup_pack_sfml/pieuvre.png")),
        sprite(cadre), font("/home/bird/CLionProjects/FlightToHFT++/assets/fonts/arial.ttf"),
        Options{font, font, font, font}, labels(questions)
{
    sprite.setTextureRect({{10, 10}, {50, 30}});
    sprite.setPosition({200.f, 25.f});

    for (int i = 0; i < SECTIONS; i++)
    {
        Options[i].setFillColor(i == 0 ? SELECTED_COLOR : DEFAULT_COLOR);
        Options[i].setString(labels[i]);
        Options[i].setPosition({WIDTH / 2.f - 50, (HEIGHT / 2.f + (i * 20))});
    }
}

sf::Sprite& PopUp::getSprite()
{
  return sprite;
}

void PopUp::display(sf::RenderWindow& window)
{
    window.draw(sprite);
    for(const auto& i : Options)
        window.draw(i);
}