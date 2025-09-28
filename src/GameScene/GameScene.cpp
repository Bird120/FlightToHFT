//
// Created by bird on 27/07/25.
//

#include "GameScene.hpp"

GameScene::GameScene(sf::RenderWindow& w)
    :Scene(w), player("/home/bird/CLionProjects/FlightToHFT++/assets/images/perso.png")
{

}
GameScene::~GameScene()
{}

void GameScene::updateAllCoins(float timer, int page)
{
    for (auto& [it, v] : coins)
    {
        if (v == page)
            it->update(timer); // juste la logique, pas de SFML
    }
}

void GameScene::drawAllCoins(int page, sf::RenderWindow& window)
{
    for (auto& [it, v] : coins)
    {
        if (v == page)
        {
            it->draw(window);
            //window.draw(it->getSprite()); // méthode qui retourne le sf::Sprite interne
        }
        }
}



void GameScene::addCoinToCoins(std::unique_ptr<AnimatedCoin> coin, int page)
{
    coins.emplace_back(std::move(coin), page);
}

void GameScene::createCoin(float x, float y, int page)
{
    auto coin = std::make_unique<AnimatedCoin>();
    coin->setPosition(x, y);
    coin->setScale(XSizeCoin, YSizeCoin );
    addCoinToCoins(std::move(coin), page);
}



PlayerSprite& GameScene::getPlayer()
{
    return player;
}

BoundaryChecker& GameScene::getBoundaryChecker()
{
    return boundaryChecker;
}

MovementSystem& GameScene::getMovementSystem()
{
    return movementSystem;
}

Direction GameScene::inputs(const sf::Event& event)
{
    //Later: for futur Entity
    (void)event;
    return Direction::DEFAULT;
}

void GameScene::initialize(bool state)
{
    //Later: if entity must be present at the beginning
    (void)state;
}


bool GameScene::update(const Direction& dir)
{
    //Base class: no need
    (void)dir;
    return false;
}

void GameScene::exit()
{

}


void GameScene::display(sf::RenderWindow& window)
{
    //Base class: no need
    (void)window;
}