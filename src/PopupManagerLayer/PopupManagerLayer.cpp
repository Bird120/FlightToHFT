//
// Created by bird on 02/10/25.
//

#include "PopupManagerLayer.hpp"


PopupManagerLayer::PopupManagerLayer() :  cadre(setTexture("/home/bird/CLionProjects/Test/Pieuvre2.png")), sprite(cadre)
{
    sprite.setPosition({180.f, 140.f});
    sprite.setScale({0.7f, 0.7f});
}



void PopupManagerLayer::display(PopupManager& manager_, sf::RenderWindow& window)
{
    if (manager_.getCurrentPopup() != nullptr && manager_.shouldShowPopup())
    {
        window.draw(sprite);

        auto tmpcurrent = manager_.getCurrentPopup();
        tmpcurrent->display(window);

    }
}