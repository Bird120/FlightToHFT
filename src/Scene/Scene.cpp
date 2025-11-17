//
// Created by bird on 28/07/25.
//

#include "Scene.hpp"



Scene::Scene(sf::RenderWindow& window) : window_(window), Menu(false)
{
}


int Scene::getScore()
{
    return score.getScore();
}


bool Scene::getFinished() const
{
    return finished;
}

bool Scene::getStateMenu()
{
    return Menu;
}

bool Scene::stateMenu(bool state)
{
    Menu = state;
    return Menu;
}


Direction Scene::getDirectionFromEvent(const sf::Event& event)
{
    return (keyboard.detectKey(event));
}

