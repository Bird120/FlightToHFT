//
// Created by bird on 28/07/25.
//

#include "Scene.hpp"

#include <Level1.hpp>


Scene::Scene(sf::RenderWindow& window)
    : window(window)
{
    playMusic("../assets/sounds/spaceadventure.ogg");

}

std::unique_ptr<Scene> Scene::newGame(const GameLevel& level)
{
    if (level == GameLevel::Level1){

        return std::make_unique<Level1>(getWindow());
    }
    return nullptr;
}

std::unique_ptr<Scene> Scene::changeGameLevel()
{
    return std::make_unique<Level1>(getWindow());
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
void Scene::playMusic(const std::filesystem::path& filename)
{
    if (!music.openFromFile(filename)) {
        std::cerr << "Scene: failed to load music" << std::endl;
    }
    music.play();
}


Direction Scene::getDirectionFromEvent(const sf::Event& event)
{
    return (keyboard.detectKey(event));
}

