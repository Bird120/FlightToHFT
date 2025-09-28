cmake_minimum_required(VERSION 3.30)
project(FlightToHFT__)

set(CMAKE_CXX_STANDARD 20)


file(GLOB_RECURSE ALL_SOURCES "src/*.cpp")

set(SOURCES "")
foreach(src ${ALL_SOURCES})
    if(
            NOT src STREQUAL "${CMAKE_SOURCE_DIR}/src/main_copy.cpp"
            AND NOT src STREQUAL "${CMAKE_SOURCE_DIR}/src/main_side.cpp"
            AND NOT src STREQUAL "${CMAKE_SOURCE_DIR}/test.cpp"
    )
        list(APPEND SOURCES ${src})
    endif()
endforeach()



list(REMOVE_ITEM SOURCES
        "${CMAKE_SOURCE_DIR}/src/main_copy.cpp"
        "${CMAKE_SOURCE_DIR}/src/main_side.cpp"
        "${CMAKE_SOURCE_DIR}/test.cpp"

)

add_executable(FlightToHFT__ ${SOURCES})

target_include_directories(FlightToHFT__ PRIVATE
        include
        src/PlayerSprite
        src/BoundaryChecker
        src/KeyboardEvents
        src/Background
        src/GameScene/Menu
        src/GameScene
        src/Game
        src/Board
        src/BoardManager
        src/Upmoving_
        src/PopUp
        src/Scene
        src/Level1
        src/Up
        src/Down
        src/BackgroundManager
        src/MovingDirection
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
