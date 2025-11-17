//
// Created by bird on 02/10/25.
//

#ifndef POPUPMANAGERLAYER_HPP
#define POPUPMANAGERLAYER_HPP


#include <SFML/Graphics.hpp>
#include "PopManager.hpp"
#include "Utilities.hpp"


struct PopupManagerLayer
{
    PopupManagerLayer();
    void display(PopupManager& manager_, sf::RenderWindow& window);
private:
    sf::Texture cadre;
    sf::Sprite sprite;

};






#endif //POPUPMANAGERLAYER_HPP
