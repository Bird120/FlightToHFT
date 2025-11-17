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

#include "ChoiceColor.hpp"
#define WIDTH 500
#define HEIGHT 880



static constexpr int SECTIONS = 4;

class PopUp
{
  sf::Text Options[SECTIONS];
  std::string labels[SECTIONS];

public:
  PopUp(const std::string& question, const std::string& choice1, const std::string& choice2, const std::string& choice3);
  PopUp(const PopUp&) = delete;
  PopUp& operator=(const PopUp&) = delete;

  PopUp(PopUp&&) = default;
  PopUp& operator=(PopUp&&) = default;

  void display(sf::RenderWindow& window) const;
  bool shouldShowPopup = false;
  //const std::array<sf::Text, SECTIONS>& getOptions() const { return Options; }
  sf::Text* getOptions();
  static int getNumbersItem();
  //std::array<sf::Text, SECTIONS>& getOptions() { return Options; }
  //const std::array<sf::Text, SECTIONS>& getOptions() const;
};

inline sf::Font getFont()
{
  sf::Font tmp_font;
  if (!tmp_font.openFromFile("/home/bird/CLionProjects/FlightToHFT++/assets/fonts/arial.ttf"))
  {
    std::cerr << "Erreur: impossible de charger la police !" << std::endl;
  }
  return tmp_font;
}


#endif //POPUP_HPP
