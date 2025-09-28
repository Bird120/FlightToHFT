//
// Created by bird on 09/07/25.
//

#ifndef KEYBOARDEVENTS_HPP
#define KEYBOARDEVENTS_HPP

#include <SFML/Window/Event.hpp>
#include <iostream>
#include "Direction.hpp"
#include "BoardManager.hpp"

#include "MovingDirection.hpp"
#include "Up.hpp"
#include "PlayerSprite.hpp"


class KeyboardEvents {

  private:

  public:
    KeyboardEvents();
    //Direction detectKey(const sf::Event& event, MovingDirection* movingDirection, BoardManager& boardManager,  PlayerSprite& getPlayer);
    //Direction detectKey(const sf::Event& event);

    template<typename T>
    Direction detectKey(const T& event);

    template<typename T, typename S, typename B, typename P>
    Direction detectKey(const T& event, S*& movingDirection, B& boardManager, P& sprite);
};
#include "KeyboardEvents.tpp"

#endif //KEYBOARDEVENTS_HPP
