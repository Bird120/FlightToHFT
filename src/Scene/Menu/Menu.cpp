//
// Created by bird on 26/07/25.
//

#include "Menu.hpp"


Menu::Menu(sf::RenderWindow& window)
:  Scene(window),
   menuOptions{font, font, font}, next_step(false)
{
    if (!music.openFromFile("/home/bird/CLionProjects/FlightToHFT++/assets/sounds/spaceadventure.ogg")) {
        std::cerr << "Scene: failed to load music" << std::endl;
    }
    music.setLooping(true);
    music.play();


    std::string labels[MENU_OPTIONS] = {"Play", "Options", "Quit"};
    for(int i = 0; i< MENU_OPTIONS; i++)
      {
        menuOptions[i].setFillColor(i == 0 ? SELECTED_COLOR : DEFAULT_COLOR);
        menuOptions[i].setString(labels[i]);
        menuOptions[i].setPosition({WIDTH_MENU / 2.f - 50, (HEIGHT_MENU / 2.f + (i * 60))});
    }
}


void Menu::initialize(bool state)
{
    (void)state;
    stateMenu(true);
}


void Menu::draw(sf::RenderWindow& window)
{

  for(int i = 0; i< MENU_OPTIONS; i++)
    window.draw(menuOptions[i]);
}

void Menu::keyboardUp()
{
    if (choiceselection.getItem() == 0)   return;

    choiceselection.notSelected(menuOptions);
    choiceselection.itemGoUp();
    choiceselection.Selected(menuOptions);
}

void Menu::keyboardDown()
{
    if (choiceselection.getItem() < MENU_OPTIONS - 1)
     {
        choiceselection.notSelected(menuOptions);
        choiceselection.itemGoDown();
        choiceselection.Selected(menuOptions);
     }
}



void Menu::keyboardEnter(sf::RenderWindow& window)
{
    auto value  = choiceselection.getItem();
    if (value == 0)
    {
        music.stop();
        this->validToNextStep();
    }
    else if (value == 2) window.close();
}

void Menu::validToNextStep()
{
    next_step = true;
}



void Menu::checkEvent(const Direction& dir)
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
                break;
            }
        default:
            break;
    }
}

bool Menu::gameStart() const
{
    return (next_step) ? true: false;
}

Direction Menu::inputs(const sf::Event& event)
{
    if (!gameStart()) {
    const auto dir = keyboard.detectKey(event);
    checkEvent(dir);
    }
    return Direction::DEFAULT;
}

bool Menu::update(const Direction& dir)
{
    (void)dir;
    if (gameStart())
    {
        return true;
    }
    return false;
}

void Menu::display(sf::RenderWindow& window)
{
    //Later: better organization with argument - window
    window.clear();

    for(int i = 0; i< MENU_OPTIONS; i++)
        window.draw(menuOptions[i]);
    window.display();

}


void Menu::exit()
{
}

//void Menu::up