//
// Created by bird on 08/10/25.
//

#include "choiceSelection.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

choiceSelection::choiceSelection()
    : item(0)
{

}
void choiceSelection::initializeItemValue(const std::size_t& value)
{
    item = value;
}

void  choiceSelection::itemGoDown()
{
    item++;
}

void  choiceSelection::itemGoUp()
{
    item--;
}

std::size_t choiceSelection::getItem() const
{
    return item;
}

std::size_t& choiceSelection::modifyItem()
{
    return item;
}

void choiceSelection::changeColor(auto& menuOptions)
{
    menuOptions[item].setFillColor(DEFAULT_COLOR);
}

/*
void choiceSelection::checkEvent(const Direction& dir, auto& menuOptions, Scene* scene, sf::RenderWindow& window)
{
    switch (dir)
    {
    case Direction::UP :
        {
            upSelected(menuOptions);
            break;
        }

    case Direction::DOWN :
        {
            downSelected(menuOptions);
            break;
        }
    case Direction::ENTER :
        {
            if (auto* menuObject = dynamic_cast<Menu*>(scene))
            {
                MenuEnterKeyboard(window,menuObject);
            }
   break;

        }
    default:
        break;
    }
}
*/



void choiceSelection::changeIteretion()
{}

void choiceSelection::notSelected(sf::Text* menuOptions)
{
    menuOptions[item].setFillColor(DEFAULT_COLOR);
}


void choiceSelection::Selected(sf::Text* menuOptions)
{
    menuOptions[item].setFillColor(SELECTED_COLOR);
}


