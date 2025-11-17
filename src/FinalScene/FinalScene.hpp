//
// Created by bird on 06/11/25.
//

#ifndef FINALSCENE_HPP
#define FINALSCENE_HPP

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "ChoiceColor.hpp"
#include "Utilities.hpp"

struct FinalScene
{
    FinalScene(sf::RenderWindow& window, int& score);
    sf::Text& getScoreDisplay();
    void setValue(std::size_t score);
    void display();

  private:
    sf::RenderWindow& m_window;
    sf::Text text_score;
    int& score_;
    sf::Texture m_texture;
    sf::Sprite m_sprite;



};


#endif //FINALSCENE_HPP
