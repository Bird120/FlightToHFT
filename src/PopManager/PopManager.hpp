//
// Created by bird on 29/09/25.
//

#ifndef POPMANAGER_HPP
#define POPMANAGER_HPP

#include "PopUp.hpp"
#include <iostream>

constexpr int sizePopupLoop = 6;


class PopupManager
{
private:
    std::vector<PopUp> pops;
    bool onlyForInitialization= true;
    bool ShowPopup = false;
    std::array<std::size_t, sizePopupLoop> answers = {2,1,2,2,2,3};

public:
    PopupManager();

    int popup_Counter = -1;

    const bool& shouldShowPopup() const;
    const PopUp* getCurrentPopup();

    void addPopUp(PopUp&& popup);

    std::size_t PopUpSize() const;
    int getPopupCounter() const { return popup_Counter;}
    void initializePopupLoop(std::size_t& value);
    void updatePopup(sf::Clock& clock, std::size_t& value);
    sf::Text* getCurrentPopup_Options();
    int getPossibleNumbersItem() const;
    std::size_t getAnswer() const;
    void addToScore();
    int getScore();
    void notShowPopup();
};





#endif //POPMANAGER_HPP
