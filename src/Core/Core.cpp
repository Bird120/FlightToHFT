//
// Created by bird on 27/07/25.
//

#include "Core.hpp"

Core::Core()
    :   window(sf::VideoMode({1200, 800}), "SFML window"),
     scene(std::make_unique<Menu>(window))
{

}

void Core::escape(const sf::Event& event)
{
    if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>())
    {
        if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
            window.close();
        if (event.is<sf::Event::Closed>())
            window.close();
    }
}

std::unique_ptr<Scene> Core::changeGameLevel()
{

    return std::make_unique<Level1>(window);
}

void Core::run()
{
    FinalScene finalScene(window, score);

        scene->initialize(false);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
          escape(*event);

            if (scene->update(scene->inputs(*event)))
            {

                auto newscene  = this->changeGameLevel();
                scene = nullptr;
                scene = std::move(newscene);

            }
            else
            {
                if (scene->getFinished())
                {
                    score = scene->getScore();
                }
            }

          }
        if (scene->getFinished())
            finalScene.display();
        else
            scene->display(window);
    }
}