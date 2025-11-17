//
// Created by bird on 29/09/25.
//

#include "PopManager.hpp"

#include "PopManager.hpp"

PopupManager::PopupManager()
{
}


void PopupManager::initializePopupLoop(std::size_t& value)
{
    if (onlyForInitialization){
        popup_Counter++;
        value = 1;
    }
}



sf::Text* PopupManager::getCurrentPopup_Options()
{
    return  pops[popup_Counter].getOptions();
}


std::size_t PopupManager::getAnswer() const
{
    return answers[popup_Counter];
}



int PopupManager::getPossibleNumbersItem() const
{
    return pops[popup_Counter].getNumbersItem();
}

const PopUp* PopupManager::getCurrentPopup()
{
    if (popup_Counter < sizePopupLoop)
    {
        return &pops[popup_Counter];
    }
    return nullptr;
}
void PopupManager::notShowPopup()
{
    ShowPopup = false;
}

const bool& PopupManager::shouldShowPopup() const
{
    return ShowPopup;
}


void PopupManager::updatePopup(sf::Clock& clock, std::size_t& value)
{
    if (popup_Counter <= 5)
    {
        if (clock.getElapsedTime().asSeconds() >= 10.f && !ShowPopup && popup_Counter !=5){
            initializePopupLoop(value);
            ShowPopup = true;
            clock.restart();
        }

        if (clock.getElapsedTime().asSeconds() >= 15.f && ShowPopup){
            onlyForInitialization = true;
            ShowPopup = false;
            clock.restart();
        }
    }

}


void PopupManager::addPopUp(PopUp&& popup)
{
    pops.push_back(std::move(popup));

}

std::size_t PopupManager::PopUpSize() const
{
    return pops.size();

}




