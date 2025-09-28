//const sf::Event& eve
template<typename T>
Direction KeyboardEvents::detectKey(const T& event)
{
    auto dir = Direction::DEFAULT;
    if (const auto* keyPressed = event.template getIf<sf::Event::KeyReleased>()) {
        if (keyPressed->scancode == sf::Keyboard::Scancode::Right)
        {
            dir = Direction::RIGHT;

        }
        else if (keyPressed->scancode == sf::Keyboard::Scancode::Left)
        {
            dir = Direction::LEFT;

        }
        else if (keyPressed->scancode == sf::Keyboard::Scancode::Up)
        {

            dir = Direction::UP;

        }
        else if (keyPressed->scancode == sf::Keyboard::Scancode::Down)
        {
            dir = Direction::DOWN;


        }
        else if (keyPressed->scancode == sf::Keyboard::Scancode::Enter)
        {
            dir = Direction::ENTER;
        }
    }
    return dir;

}

//const sf::Event& event, MovingDirection* movingDirection, BoardManager& boardManager, PlayerSprite& sprite

template<typename T, typename S, typename B, typename P>
Direction KeyboardEvents::detectKey(const T& event, S*& movingDirection, B& boardManager, P& sprite)
{
    auto dir = Direction::DEFAULT;
    if (const auto* keyPressed = event.template getIf<sf::Event::KeyReleased>()) {
        if (keyPressed->scancode == sf::Keyboard::Scancode::Right)
        {
            std::cout<< "key right has been pressed!" << std::endl;
            dir = Direction::RIGHT;

        }
        else if (keyPressed->scancode == sf::Keyboard::Scancode::Left)
        {
            std::cout<< "key right has been pressed!" << std::endl;
            dir = Direction::LEFT;

        }
        else if (keyPressed->scancode == sf::Keyboard::Scancode::Up)
        {
            movingDirection = nullptr;
            movingDirection = new Upp();
            boardManager.checkIfBoard(sprite. getXPosition(), sprite. getYPosition(),movingDirection->getMoving());

            movingDirection->initializeMoving(sprite.getSprite(), movingDirection->getMoving().currentboard_, movingDirection->getMoving().availableBoard);


            std::cout<< "key right has been pressed! UP" << std::endl;
            dir = Direction::DEFAULT;

        }
        else if (keyPressed->scancode == sf::Keyboard::Scancode::Down)
        {
            std::cout<< "key right has been pressed!" << std::endl;
            dir = Direction::DOWN;


        }
        else if (keyPressed->scancode == sf::Keyboard::Scancode::Enter)
        {
            std::cout<< "key right has been pressed!" << std::endl;
            dir = Direction::ENTER;
        }
    }
    return dir;
}