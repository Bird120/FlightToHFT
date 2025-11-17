//
// Created by bird on 20/07/25.
//

#include "BackgroundManager.hpp"


BackgroundManager::BackgroundManager()
    : texture(setTexture("/home/bird/CLionProjects/FlightToHFT++/assets/background/level1_1.jpeg")), sprite(texture)
{
    initBackgrounds();
    currentLevel.first = GameLevel::Level1;
    currentLevel.second = 1;
}

void BackgroundManager::moveLevel(const GameLevel& level)
{
    currentLevel.first = level;
    currentLevel.second = 1;
}


void BackgroundManager::setNewPage(const bool& state)
{
    newPage = state;
}


bool&  BackgroundManager::getNewPage()
{
    return newPage;
}

int BackgroundManager::getPage() const
{
    return getCurrentPageNumber();
}
int BackgroundManager::getCurrentPageNumber() const
{
    return (currentLevel.second);
}
GameLevel BackgroundManager::getCurrentGameLevel() const
{
    return static_cast<GameLevel>(currentLevel.first);
}


sf::Sprite& BackgroundManager::displayCurrentBackground()
{
    sprite.setTexture(backgrounds[currentLevel.first][currentLevel.second -1]);
    return sprite;
}


bool BackgroundManager::getFinished() const
{
    return finished;
}


bool BackgroundManager::changeBackground_(const bool& state)
{
    if (state == true)
    {
        if (currentLevel.second == 3)
        {
            finished = true;
            return false;
        }

        //{

           /* auto it = static_cast<int>(currentLevel.first);

            if (it < 4 && it > 0 )
            {
                currentLevel.first = static_cast<GameLevel>(it);
                currentLevel.second = 1;
            }*/
        //}

        currentLevel.second = (static_cast<int>(currentLevel.second)+ 1);
        
    }
    return true;
}

void BackgroundManager::initBackgrounds()
{
    backgrounds[GameLevel::Level1] = {
        sf::Texture(setTexture("/home/bird/CLionProjects/FlightToHFT++/assets/background/level1_1.jpeg")),
        sf::Texture(setTexture("/home/bird/CLionProjects/FlightToHFT++/assets/background/level1_2.jpeg")),
       sf::Texture(setTexture("/home/bird/CLionProjects/FlightToHFT++/assets/background/level1_3.jpeg"))
    };

    backgrounds[GameLevel::Level2] = {
        sf::Texture(setTexture("/home/bird/CLionProjects/FlightToHFT++/assets/background/level2_1.jpeg")),
        sf::Texture(setTexture("/home/bird/CLionProjects/FlightToHFT++/assets/background/level2_2.jpeg")),
       sf::Texture(setTexture("/home/bird/CLionProjects/FlightToHFT++/assets/background/level2_3.jpeg"))
    };

    backgrounds[GameLevel::Level3] = {
        sf::Texture(setTexture("/home/bird/CLionProjects/FlightToHFT++/assets/background/level3_1.jpeg")),
        sf::Texture(setTexture("/home/bird/CLionProjects/FlightToHFT++/assets/background/level3_2.jpeg")),
        sf::Texture(setTexture("/home/bird/CLionProjects/FlightToHFT++/assets/background/level3_3.jpeg"))
    };
}

 std::pair<GameLevel,int> BackgroundManager::getCurrentLevel(const GameLevel& level)
{
    (void)level;
    GameLevel tmp = currentLevel.first;
    auto tmp_pos = static_cast<int>(currentLevel.second);
    return {tmp, tmp_pos};

}


void BackgroundManager::notify(const bool& state)
{
    changeBackground = state;
}

