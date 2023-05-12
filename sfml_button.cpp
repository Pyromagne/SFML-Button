////////////////////////////////////////////////////////////
///
/// SFML BUTTON LIBRARY
/// Copyright (c) 2023 Pyromagne
///
////////////////////////////////////////////////////////////

#include "sfml_button.hpp"

unsigned int Button::count = 0;

void Button::setButtonFont(sf::Font& font)
{
    buttonLabel.setFont(font);
}