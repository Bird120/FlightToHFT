//
// Created by bird on 26/07/25.
//

#include "Menu.hpp"


Menu::Menu(sf::RenderWindow& w)
:  Scene(w), item(0), font("/home/bird/CLionProjects/FlightToHFT++/assets/fonts/arial.ttf") ,
   menuOptions{font, font, font}, next_step(false)
{
std::string labels[MENU_OPTIONS] = {"Play", "Options", "Quit"};
for(int i = 0; i< MENU_OPTIONS; i++)
  {
    menuOptions[i].setFillColor(i == 0 ? SELECTED_COLOR : DEFAULT_COLOR);
    menuOptions[i].setString(labels[i]);
    menuOptions[i].setPosition({WIDTH / 2.f - 50, (HEIGHT / 2.f + (i * 60))});
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
void Menu::notSelected()
{
    menuOptions[item].setFillColor(DEFAULT_COLOR);
}

void Menu::Selected()
{
    menuOptions[item].setFillColor(SELECTED_COLOR);
}

void Menu::moveUp()
{
    if (item == 0)   return;

    notSelected();
    item--;
    Selected();
}

void Menu::moveDown()
{
    if (item < MENU_OPTIONS - 1)
     {  notSelected();
        item++;
        Selected();
     }
}


int Menu::getItemEnter() const
{
    return item;
}

void Menu::checkEvent(const Direction& dir)
{
        switch (dir)
        {
        case Direction::UP :
            {
                moveUp();
                break;
            }

        case Direction::DOWN :
            {
                moveDown();
                break;
            }
        case Direction::ENTER :
            {
                auto value  = getItemEnter();
                if (value == 0) next_step = true;
                else if (value == 2) getWindow().close();
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
    (void)window;
    getWindow().clear();

    for(int i = 0; i< MENU_OPTIONS; i++)
        getWindow().draw(menuOptions[i]);
    getWindow().display();

}


void Menu::exit()
{
}

//void Menu::up