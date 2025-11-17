//
// Created by bird on 06/11/25.
//

#include "FinalScene.hpp"

FinalScene::FinalScene(sf::RenderWindow& window, int& score)
    : m_window(window),text_score(font), score_(score), m_texture(setTexture("/home/bird/CLionProjects/FlightToHFT++/assets/images/end.png")),
     m_sprite(m_texture)

{
    m_sprite.setPosition({150.f, 100.f});
    m_sprite.setScale({0.5f, 0.5f});
    text_score.setCharacterSize(60);
    text_score.setFillColor(SELECTED_COLOR);
    text_score.setString("Score: ");

    text_score.setPosition({600,20});
}
void FinalScene::setValue(std::size_t score)
{
    text_score.setString("Score: " + std::to_string(score) + " / 240");
}

sf::Text& FinalScene::getScoreDisplay()
{
    return text_score;
}

void FinalScene::display()
{
    m_window.clear(sf::Color::White);
    m_window.draw(m_sprite);
    this->setValue(static_cast<std::size_t>(score_));
    m_window.draw(getScoreDisplay());
    m_window.display();
}