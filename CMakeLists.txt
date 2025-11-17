cmake_minimum_required(VERSION 3.30)
project(FlightToHFT__)

set(CMAKE_CXX_STANDARD 20)


file(GLOB_RECURSE SOURCES "src/*.cpp")




add_executable(FlightToHFT__ ${SOURCES})


target_include_directories(FlightToHFT__ PRIVATE  -Wall  -Wextra -Werror
        include
        src/PlayerSprite
        src/BoundaryChecker
        src/KeyboardEvents
        src/Background
        src/Scene/Menu
        src/Scene/GameScene
        src/Board
        src/BoardManager
        src/Upmoving_
        src/PopUp
        src/PopManager
        src/Score
        src/Scene
        src/FinalScene
        src/Coin
        src/ChoiceSelection
        src/Scene/GameScene/Level1
        src/Wall
        src/WallManager
        src/HorizontalMove
        src/MovingDirection/Up
        src/MovingDirection/Right
        src/MovingDirection/Left
        src/MovingDirection/Down
        src/PopupManagerLayer
        src/BackgroundManager
        src/MovingDirection
        src/Collisions
        src/CollisionsManager
        src/MovementSystem)


set(SFML_DIR "/usr/lib/cmake/SFML")
find_package(SFML 3 REQUIRED COMPONENTS System Window Graphics Audio Network)

target_link_libraries(FlightToHFT__
        sfml-system
        sfml-window
        sfml-graphics
        sfml-audio
        sfml-network
)


target_compile_options(FlightToHFT__ PRIVATE -Wall -Wextra -pedantic)


file(COPY assets/ DESTINATION ${CMAKE_BINARY_DIR}/assets)
