//
// Created by bird on 18/07/25.
//

#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Font.hpp>
#include <iostream>

inline sf::Font font("/home/bird/CLionProjects/FlightToHFT++/assets/fonts/arial.ttf");
inline sf::Texture setTexture(const std::filesystem::path &filename){
    sf::Texture texture_tmp;
    if (!texture_tmp.loadFromFile(filename))
        std::cerr << "Error: Loading texture from player, path:  " << filename << std::endl;
    texture_tmp.setSmooth(true);

    return texture_tmp;
}
inline sf::Texture cadre(setTexture("/home/bird/CLionProjects/Test/Pieuvre2.png"));
inline sf::Sprite cadre_sprite(cadre);




#endif //UTILITIES_HPP
