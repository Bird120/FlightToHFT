//
// Created by bird on 27/07/25.
//

#ifndef GAMESCENE_HPP
#define GAMESCENE_HPP

#include <SFML/Graphics/Sprite.hpp>

#include "Coin2.hpp"
#include "PlayerSprite.hpp"
#include "BoundaryChecker.hpp"
#include "Scene.hpp"

#include <variant>

#include <utility>

constexpr float DefaultTimer = 0.0;
constexpr float XSizeCoin = 0.4f;
constexpr float YSizeCoin = 0.3f;

class GameScene: public Scene {
    protected:
      PlayerSprite player;
      BoundaryChecker boundaryChecker;
      MovementSystem movementSystem;
      sf::Texture coinTexture;
      PlayerSprite& getPlayer();
      BoundaryChecker& getBoundaryChecker();
      MovementSystem& getMovementSystem();
      std::vector<std::pair<std::unique_ptr<AnimatedCoin>, int>> coins;
      void addCoinToCoins(std::unique_ptr<AnimatedCoin> coin, int page);
      void createCoin(float x, float y, int page);
      //std::optional<sf::Sprite> accessAllCoins(const CoinState& state,  float timer, int page, sf::RenderWindow& window);
    void updateAllCoins(float timer, int page);
    void drawAllCoins(int page, sf::RenderWindow& window);


    public:
      GameScene(sf::RenderWindow& w);
     ~GameScene();

      void initialize(bool state) override;
      Direction inputs(const sf::Event& event) override;
      bool update(const Direction& dir) override;
      void exit() override;
      void display(sf::RenderWindow& window) override;
      void setterPosition();
      bool canPlayerMove(const Direction& dir);
      void movementSystem_(const Direction& dir, const sf::Event& event) const;


};
#endif //GAMESCENE_HPP
