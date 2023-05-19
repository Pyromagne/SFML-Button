////////////////////////////////////////////////////////////
// MIT License
//
// Copyright (c) 2023 Pyromagne
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
////////////////////////////////////////////////////////////
#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED
////////////////////////////////////////////////////////////
// HEADERS
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <iostream>

const sf::Color defaultColor = sf::Color(255,255,255);
const sf::Color defaultHover = sf::Color(191, 191, 191);
const sf::Color defaultPress = sf::Color(153, 153, 153);

<<<<<<< HEAD
struct ColorSet
=======
struct ButtonColorSet
>>>>>>> 1b2ed361805544cb7f949c2f695a9593c8654d9a
{
    public:
    sf::Color color;
    sf::Color hover;
    sf::Color press;

<<<<<<< HEAD
    ColorSet();
=======
    ButtonColorSet();
    ButtonColorSet(sf::Color, sf::Color, sf::Color);

    void setButtonColor(sf::Color, sf::Color, sf::Color);
>>>>>>> 1b2ed361805544cb7f949c2f695a9593c8654d9a
};


////////////////////////////////////////////////////////////
///
/// @brief Base class for button
///
////////////////////////////////////////////////////////////

class Button
{
    public:
    virtual void getButtonStatus(sf::RenderWindow&, sf::Event&) = 0;
    virtual void draw(sf::RenderWindow&) = 0;
    virtual void setButtonFont(sf::Font&);
    virtual void setButtonLable(std::string, const sf::Color&, float) = 0;
<<<<<<< HEAD
    void setButtonColor(sf::Color, sf::Color, sf::Color);

=======

    ButtonColorSet bcs;
>>>>>>> 1b2ed361805544cb7f949c2f695a9593c8654d9a
    bool isHover = false;
    bool isPressed = false;
    bool isActive = true;
    static unsigned int count;

    protected:
    bool autoSize = false;
    sf::Text buttonLabel;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;
    sf::Vector2f buttonPos;
    sf::FloatRect labelRect;
    std::string label;
<<<<<<< HEAD
    ColorSet buttonColorSet;
=======
>>>>>>> 1b2ed361805544cb7f949c2f695a9593c8654d9a
};

#endif // BUTTON_HPP_INCLUDED
