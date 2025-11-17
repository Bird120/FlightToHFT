//
// Created by bird on 20/07/25.
//

#ifndef BACKGROUNDMANAGER_HPP
#define BACKGROUNDMANAGER_HPP

#include "Background.hpp"
#include <atomic>
#include "Order.hpp"
#include "GameLevel.hpp"
#include <map>

class BackgroundManager
{

private:
    std::map<GameLevel, std::vector<sf::Texture>> backgrounds;
    std::atomic<bool> changeBackground = false;
    std::pair<GameLevel, int> currentLevel;
    sf::Texture texture;
    sf::Sprite sprite;
    bool newPage = false;
    bool finished = false;

public:
    BackgroundManager();
    //void addBackground(const Background& background);
    void initBackgrounds();
    void notify(const bool& state );
    bool changeBackground_(const bool& state);
    std::pair<GameLevel,int> getCurrentLevel(const GameLevel& level);
    GameLevel getCurrentGameLevel() const;
    sf::Sprite& displayCurrentBackground();
    int getCurrentPageNumber() const;
    int getPage() const;
    void moveLevel(const GameLevel& level);
    bool& getNewPage();
    void setNewPage(const bool& state);
    bool getFinished() const;






};
#endif //BACKGROUNDMANAGER_HPP
