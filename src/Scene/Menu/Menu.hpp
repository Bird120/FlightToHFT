//
// Created by bird on 26/07/25.
//

#ifndef MENU_HPP
#define MENU_HPP

#define MENU_OPTIONS 3
#define WIDTH_MENU 500
#define HEIGHT_MENU 400
#include <SFML/Graphics.hpp>
#include <array>
#include "Direction.hpp"
#include <SFML/Graphics/Text.hpp>
#include "Scene.hpp"
#include "choiceSelection.hpp"



class Menu final : public Scene {
  private:
      sf::Text menuOptions[MENU_OPTIONS];
      bool next_step;
      choiceSelection choiceselection;

  public:
    explicit Menu(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
    void moveUp();
    void moveDown();

    void checkEvent(const Direction& dir);
    void initialize(bool state) override;
    Direction inputs(const sf::Event& event) override;
    bool update(const Direction& dir) override;
    void exit() override;
    void display(sf::RenderWindow& window) override;
    bool gameStart() const;
    void validToNextStep();
    void keyboardUp() override;
    void keyboardDown() override;
    void keyboardEnter(sf::RenderWindow& window) override;

};
#endif //MENU_HPP
