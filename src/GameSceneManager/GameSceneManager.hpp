//
// Created by bird on 27/07/25.
//

#ifndef GAMESCENEMANAGER_HPP
#define GAMESCENEMANAGER_HPP


#include <memory>
#include "GameScene.hpp"

class GameSceneManager {
  private:
    std::unique_ptr<GameScene> gameScene;

  public:
    explicit  GameSceneManager(std::unique_ptr<GameScene> &&gameScene_tmp);

};

#endif //GAMESCENEMANAGER_HPP
