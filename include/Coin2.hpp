//
// Created by bird on 25/07/25.
//

#ifndef COIN_HPP
#define COIN_HPP
#include <SFML/Graphics.hpp>
#include <vector>
#include <SFML/Graphics/Rect.hpp>

#include "Utilities.hpp"
constexpr float FrameTime  = 0.08f;
constexpr int  FrameCount =  9;
constexpr int FrameWidth  = 202;
constexpr int FrameHeight  = 700;


enum class CoinState  {UPDATE, DRAW};
class AnimatedCoin
{
public:
    AnimatedCoin()
        : texture(setTexture("/home/bird/CLionProjects/FlightToHFT++/assets/images/coin.png")),sprite(texture), currentFrame(0), timeSinceLastFrame(0.f)
    {


        for (int i = 0; i < 9; ++i) {
            frames.push_back(sf::IntRect({i * FrameWidth -61, 0}, {FrameWidth -2, FrameHeight + 2}));
        }
        sprite.setTextureRect(frames[0]);
    }

    void update(float deltaTime) {
        timeSinceLastFrame += deltaTime;
        if (timeSinceLastFrame >= FrameTime)
        {
            timeSinceLastFrame = 0.f;
            currentFrame = (currentFrame + 1) % FrameCount;
            sprite.setTextureRect(frames[currentFrame]);
        }
    }

    sf::Sprite& getSprite()
    {  return sprite;}

    void setScale(float x, float y) {
        sprite.setScale({x, y});
    }

    void draw(sf::RenderWindow& window) {
        window.draw(sprite);
    }

    void setPosition(float x, float y) {
        sprite.setPosition({x, y});
    }

private:
    const sf::Texture texture;
    sf::Sprite sprite;
    std::vector<sf::IntRect> frames;
    int currentFrame;
    float timeSinceLastFrame;
};

#endif //COIN_HPP
