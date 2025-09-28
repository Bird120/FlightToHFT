//
// Created by bird on 26/07/25.
//

#ifndef MENU_HPP
#define MENU_HPP


#include <SFML/Graphics.hpp>
#include <array>
#include "Direction.hpp"
#include <SFML/Graphics/Text.hpp>
#include "Scene.hpp"

const sf::Color SELECTED_COLOR = sf::Color::Blue;
const sf::Color DEFAULT_COLOR = sf::Color::White;
#define MENU_OPTIONS 3
#define WIDTH 500
#define HEIGHT 400

class Menu final : public Scene {
  private:
      int item;
      sf::Font font;
      sf::Text menuOptions[MENU_OPTIONS];
      bool next_step;
  public:
    Menu(sf::RenderWindow& w);
    void draw(sf::RenderWindow& window);
    void moveUp();
    void moveDown();
    int getItemEnter() const;
    void notSelected();
    void Selected();
    void checkEvent(const Direction& dir);
    void initialize(bool state) override;
    Direction inputs(const sf::Event& event) override;
    bool update(const Direction& dir) override;
    void exit() override;
    void display(sf::RenderWindow& window) override;
    bool gameStart() const;


};
#endif //MENU_HPP
