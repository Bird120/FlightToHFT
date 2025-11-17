//
// Created by bird on 08/10/25.
//

#ifndef CHOICESELECTION_HPP
#define CHOICESELECTION_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include "Direction.hpp"
#include <iostream>
#include "ChoiceColor.hpp"
#include "Scene.hpp"

class choiceSelection
{
  private:
    std::size_t item;
    std::size_t CHOICE_OPTIONS = 0;

  public:
    choiceSelection();
    void changeIteretion();
    void changeColor(auto& menuOptions);
    void itemGoDown();
    void itemGoUp();
    void notSelected(sf::Text* menuOptions);
    void Selected(sf::Text* menuOptions);
    std::size_t getItem() const;
    void initializeItemValue(const std::size_t& value);
    std::size_t& modifyItem();
};



#endif //CHOICESELECTION_HPP
