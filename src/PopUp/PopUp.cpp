//
// Created by bird on 17/08/25.
//

#include "PopUp.hpp"


PopUp::PopUp(const std::string& question, const std::string& choice1, const std::string& choice2, const std::string& choice3)
    :   Options{font,font,font,font}, labels{question,choice1, choice2, choice3}
{
    // Charger la police dans le membre 'font' (doit réussir avant setFont)

    for (int i = 0; i < SECTIONS; i++)
    {

        if (i == 0)
            Options[i].setFillColor(QUESTION_COLOR);
        else if (i == 1)
            Options[i].setFillColor(SELECTED_COLOR);
        else
            Options[i].setFillColor(DEFAULT_COLOR);


        Options[i].setFont(font);
        Options[i].setCharacterSize(20);
        Options[i].setString(labels[i]);
        Options[i].setPosition({WIDTH / 2.f , (HEIGHT / 2.f + (i * 60))});
    }
}

sf::Text* PopUp::getOptions()
{
    return Options;
}

int PopUp::getNumbersItem()
{
    return SECTIONS;
}

void PopUp::display(sf::RenderWindow& window) const
{
    for(const auto& i : Options)
    {
        std::string l =  i.getString();
        window.draw(i);
    }
}

