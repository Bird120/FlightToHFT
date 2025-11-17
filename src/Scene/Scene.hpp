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
#include "PopupManagerLayer.hpp"
#include <memory>
#include "Score.hpp"


#include <SFML/Graphics/RenderWindow.hpp>

class Scene
{
    protected:
      sf::RenderWindow& window_;
      bool Menu;

      sf::Music music;
      KeyboardEvents keyboard;
      sf::Clock clock;
      sf::Clock popManagerClock;

      BackgroundManager backgrounds;
      bool stateMenu(bool state);
      inline BackgroundManager& getBackgrounds() { return backgrounds; }
      bool finished = false;
      Score score;

    public:
      explicit Scene(sf::RenderWindow& window);

      virtual ~Scene() = default;
      void playMusic(const std::filesystem::path& filename);
      Direction getDirectionFromEvent(const sf::Event& event) ;
      virtual void initialize(bool state) = 0;
      virtual Direction inputs(const sf::Event& event) = 0;
      virtual bool update(const Direction& dir) = 0;
      virtual void exit() = 0;
      virtual void display(sf::RenderWindow& window) = 0;
      virtual void keyboardUp() = 0;
      virtual void keyboardDown() = 0;
      virtual void keyboardEnter(sf::RenderWindow& window) = 0;
      int getScore();
      Score& getObjScore();

    bool getFinished() const;

      inline bool getStateMenu();
      inline sf::Clock& getClock() { return clock; }
      inline sf::Clock& getPopManagerClock() { return popManagerClock; }

      inline sf::RenderWindow& getWindow() const;

};

inline sf::RenderWindow& Scene::getWindow() const
{
    return window_;
}



#endif //SCENE_HPP
