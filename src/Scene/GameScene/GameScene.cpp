//
// Created by bird on 27/07/25.
//

#include "GameScene.hpp"

GameScene::GameScene(sf::RenderWindow& window)
    :Scene(window), player("/home/bird/CLionProjects/FlightToHFT++/assets/images/right3.png")
{

}


void GameScene::verifyIfCollisionDetect(int iterator)
{
    if (iterator == -1) return;
    else
    {
        eraseCoin(iterator);
    }
}



void GameScene::eraseCoin(unsigned int iterator)
{
    coins.erase(coins.begin() + iterator);
}



std::vector<std::pair<std::unique_ptr<Coin>, int>>& GameScene::getCoins()
{
    return coins;
}




void GameScene::drawAllCoins(int page, sf::RenderWindow& window)
{
    for (auto& [it, v] : coins)
    {
        if (v == page)
        {
            it->draw(window);
        }
        }
}





void GameScene::addCoinToCoins(std::unique_ptr<Coin> coin, int page)
{
    coins.emplace_back(std::move(coin), page);
}

void GameScene::createCoin(float x, float y, int page)
{
    auto coin = std::make_unique<Coin>();
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
    (void)window;
}

void GameScene::keyboardUp(){}
void GameScene::keyboardDown(){}
void GameScene::keyboardEnter(sf::RenderWindow& window)
{
    (void)window;
}