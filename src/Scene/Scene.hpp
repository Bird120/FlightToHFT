//
// Created by bird on 28/07/25.
//

#ifndef SCENE_HPP
#define SCENE_HPP

#include "Background.hpp"
#include "KeyboardEvents.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Window/Event.hpp>
#include "Direction.hpp"
#include "BackgroundManager.hpp"

class Scene
{
    protected:
      sf::RenderWindow& window;
      sf::Music music;
      KeyboardEvents keyboard;
      sf::Clock clock;
      bool Menu;
      BackgroundManager backgrounds;

      bool stateMenu(bool state);
      inline BackgroundManager& getBackgrounds() { return backgrounds; }


    public:
      Scene(sf::RenderWindow& window);
      virtual ~Scene() = default;
      void playMusic(const std::filesystem::path& filename);
      Direction getDirectionFromEvent(const sf::Event& event) ;
      virtual void initialize(bool state) = 0;
      virtual Direction inputs(const sf::Event& event) = 0;
      virtual bool update(const Direction& dir) = 0;
      virtual void exit() = 0;
      virtual void display(sf::RenderWindow& window) = 0;
      inline bool getStateMenu();
      inline sf::Clock& getClock() { return clock; }
      std::unique_ptr<Scene> changeGameLevel();
      std::unique_ptr<Scene> newGame(const GameLevel& level);
      inline sf::RenderWindow& getWindow()  { return window; }

};
#endif //SCENE_HPP
