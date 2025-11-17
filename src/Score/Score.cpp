//
// Created by bird on 11/10/25.
//

#include "Score.hpp"

Score::Score()
    : text_score(font)
{
  text_score.setCharacterSize(60);
  text_score.setFillColor(SELECTED_COLOR);
  text_score.setString("Score: ");
  //text_score.setString("Score: ") + std::to_string(score);

  text_score.setPosition({800,20});
}

void Score::setValue(std::size_t score)
{
  text_score.setString("Score: " + std::to_string(score));
}

sf::Text& Score::getScoreDisplay()
{
  return text_score;
}

void Score::addToScore(int value)
{
  score += value;
}

int& Score::addScore()
{
  return score;
}

int Score::getScore() const
{
  return score;
}