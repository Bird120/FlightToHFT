//
// Created by bird on 29/08/25.
//

#ifndef LEVEL1_HPP
#define LEVEL1_HPP


#include "PopUp.hpp"
#include "GameScene.hpp"
#include "MovingDirection.hpp"
#include "choiceSelection.hpp"
#include "Score.hpp"
#include "Coin.hpp"
#include "CollisionsManager.hpp"

class Level1 final : public GameScene
{
  private:
    bool begin;
    choiceSelection choiceselection;
    CollisionsManager collisions_manager_;
    sf::Clock deltaClock;

  public:
    explicit Level1(sf::RenderWindow& window);
    ~Level1() override = default;

    void initialize(bool state) override;
    Direction inputs(const sf::Event& event) override;
    bool update(const Direction& dir) override;
    void exit() override;
    void display(sf::RenderWindow& window) override;
  PopupManager popManager;
  PopupManagerLayer popManagerLayer;
  PopupManager& getPopManager();
  void updateCollisions();
  void updateMove();
  void updatePopUp();
  void checkEvent(const Direction& dir);
  void keyboardUp() override;
  void keyboardDown() override;
  void keyboardEnter(sf::RenderWindow& window) override;
};

#endif //LEVEL1_HPP
