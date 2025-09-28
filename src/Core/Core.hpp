//
// Created by bird on 27/07/25.
//

#ifndef GAME_HPP
#define GAME_HPP


#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Exception.hpp>
#include "KeyboardEvents.hpp"
#include "PlayerSprite.hpp"
#include "BoundaryChecker.hpp"
#include "Background.hpp"

#include "Coin2.hpp"
#include "GameLevel.hpp"
#include "Menu.hpp"
#include "Scene.hpp"
#include "BackgroundManager.hpp"


class Core {
  private:
    sf::RenderWindow window;
    std::unique_ptr<BackgroundManager> manager;
    std::unique_ptr<Scene> scene;
    sf::Clock clock;


  public:
    Core();
    void run();
    void update();
    void render();
    void exit();
    void escape(const sf::Event& event);
};


#endif //GAME_HPP
