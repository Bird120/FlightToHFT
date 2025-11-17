//
// Created by bird on 29/08/25.
//

#include "Level1.hpp"


Level1::Level1(sf::RenderWindow& window)
    :GameScene(window), begin(true)
{
    if (!music.openFromFile("assets/sounds/spaceadventure.ogg")) {
        std::cerr << "Level1: failed to load music" << std::endl;
    }

    music.setLooping(true);
    music.play();
    createCoin(700.f, 200.f, 1);
    createCoin(600.f, 450.f, 1);
    createCoin(230.f, 180.f, 2);
    createCoin(700.f, 460.f, 2);
    createCoin(380.f, 420.f, 3);
    createCoin(830.f, 450.f, 3);

    popManager.addPopUp(PopUp("1 - Why is false sharing harmful in HFT multithreaded systems?",
        "It causes the compiler to remove necessary optimizations",
        "It forces multiple cores to fight over the same cache line",
        "It prevents data from being saved in L1 cache"));

    popManager.addPopUp(PopUp("2 - In a low-latency trading system, what is the main reason\n\tto use lock-free data structures?",
        "They avoid kernel scheduling delays caused by blocked threads",
        "They are always faster than any lock-based alternative",
        "They require less CPU cache than mutex-based algorithms"));
    popManager.addPopUp(PopUp("3 - Which technique is commonly used to\n\tachieve deterministic latency in HFT?",
        "Using dynamic memory allocation at runtime (new, resize)",
        "Pinning threads to specific CPU cores (CPU affinity)",
        "Running everything on a single OS thread"));
    popManager.addPopUp(PopUp("4 - Why is std::chrono::steady_clock preferred\n\tin latency-critical timing?",
        "It provides nanosecond accuracy",
        "It is monotonic and not affected by system clock adjustments",
        "It uses TSC (Time Stamp Counter) directly"));
    popManager.addPopUp(PopUp("5 - What is the advantage of using a ring buffer\n\tin an HFT messaging system?",
        "It automatically prevents race conditions",
        "It allows fixed-size, contiguous, cache-friendly message storage",
        "It supports dynamic resizing without memory fragmentation"));
    popManager.addPopUp(PopUp("6 - What is the purpose of prefetching in low-latency applications?",
        "To fetch data from disk before using it",
        "To warm up the CPU branch predictor",
        "To bring memory into cache before the code actually needs it"));
    choiceselection.initializeItemValue(1);
    getPlayer().setterPosition(getWindow(),begin);
}

PopupManager& Level1::getPopManager()
{
    return popManager;
}


void Level1::initialize(bool state)
{
    //no need for the Level1
    (void)state;
    stateMenu(true);
    this->begin = false;
}

Direction Level1::inputs(const sf::Event& event)
{
    return keyboard.detectKey(event);
}


bool Level1::update(const Direction& dir)
{
    if (popManager.shouldShowPopup())
    {
        checkEvent(dir);
    }
    else if (getBoundaryChecker().canMove(dir, getPlayer(), getWindow(), backgrounds))
    {
        getMovementSystem().changePosition(dir, getPlayer(), backgrounds.getNewPage(), backgrounds.getPage());
        getPlayer().displayRightSprite(dir);

    }
    if (backgrounds.getFinished())
    {
        finished = true;
        return false;
    }
    return false;
}


void Level1::updateCollisions()
{
    auto result = collisions_manager_.checkIfDetect(getCoins(), getPlayer().getSprite(),backgrounds.getPage(),score.addScore());
    verifyIfCollisionDetect(result);
}

void Level1::updateMove()
{
    auto* movingDirection = movementSystem.getMovingDirection();

    float dt = deltaClock.restart().asSeconds();
    const bool playerInMovement = (movingDirection != nullptr && movingDirection->getMoving().upmoving);
    const bool playerMovementFinished = (movingDirection != nullptr && !movingDirection->getMoving().upmoving);

    if (playerInMovement)
    {
        movingDirection->doTheMove(dt, getPlayer().getSprite());
    }
    else if (playerMovementFinished)
    {
        getMovementSystem().reset();
    }
}

void Level1::updatePopUp()
{
    popManager.updatePopup(getPopManagerClock(), choiceselection.modifyItem());
}


void Level1::display(sf::RenderWindow& window)
{
    window.clear();

    updatePopUp();
    updateMove();
    updateCollisions();

    window.draw(backgrounds.displayCurrentBackground());

    auto& sprite =getPlayer().getSprite();

    window.draw(sprite);
    drawAllCoins(backgrounds.getPage(), window);

    if (popManager.getCurrentPopup() != nullptr && popManager.shouldShowPopup())
    {
        popManagerLayer.display(popManager, window);
    }

    score.setValue(static_cast<std::size_t>(score.getScore()));
    window.draw(score.getScoreDisplay());
    window.display();
}

void Level1::exit()
{
}


void Level1::checkEvent(const Direction& dir)
{
        switch (dir)
        {
        case Direction::UP :
            {
                keyboardUp();
                break;
            }

        case Direction::DOWN :
            {
                keyboardDown();
                break;
            }
        case Direction::ENTER :
            {
                this->keyboardEnter(getWindow());
                popManager.notShowPopup();
                break;
            }
        default:
            break;
        }
}


void Level1::keyboardUp()
{
    if (choiceselection.getItem() == 1) return;

    choiceselection.notSelected(popManager.getCurrentPopup_Options());
    choiceselection.itemGoUp();
    choiceselection.Selected(popManager.getCurrentPopup_Options());
}
void Level1::keyboardDown()
{
    if (static_cast<int>(choiceselection.getItem()) < (popManager.getPossibleNumbersItem()  - 1))
    {
        choiceselection.notSelected(popManager.getCurrentPopup_Options());
        choiceselection.itemGoDown();
        choiceselection.Selected(popManager.getCurrentPopup_Options());
    }
}
void Level1::keyboardEnter(sf::RenderWindow& window)
{
    (void)window;
    auto value  = choiceselection.getItem();
    if (value == popManager.getAnswer())
    {
        score.addToScore(30);
    }
    else
        return;
}