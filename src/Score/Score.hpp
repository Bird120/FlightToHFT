//
// Created by bird on 11/10/25.
//

#ifndef SCORE_HPP
#define SCORE_HPP

#include <SFML/Graphics/Text.hpp>
#include "Utilities.hpp"
#include "ChoiceColor.hpp"

struct Score
{
  private:
    sf::Text text_score;
    int score = 0;

  public:
    Score();
    void setValue(std::size_t score);
    sf::Text& getScoreDisplay();
    void addToScore(int value);
    int& addScore();
    int getScore() const;

};
#endif //SCORE_HPP
