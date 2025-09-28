//
// Created by bird on 27/07/25.
//

#include "GameSceneManager.hpp"


GameSceneManager::GameSceneManager(std::unique_ptr<GameScene>&& gameScene_tmp)
    :gameScene(std::move(gameScene_tmp))
{

}