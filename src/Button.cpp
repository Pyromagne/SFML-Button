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

////////////////////////////////////////////////////////////
// HEADERS
////////////////////////////////////////////////////////////
#include "../include/Button.hpp"

ColorSet::ColorSet()
{
    this->color = defaultColor;
    this->hover = defaultHover;
    this->press = defaultPress;
}

ColorSet::ColorSet(sf::Color color)
{
    init(color, color, color);
}

ColorSet::ColorSet(sf::Color color, sf::Color hover, sf::Color press)
{
    init(color, hover, press);
}

void ColorSet::init(sf::Color color, sf::Color hover, sf::Color press)
{
    this->color = color;
    this->hover = hover;
    this->press = press;
}

void Button::setButtonFont(sf::Font& font)
{
    buttonLabel.setFont(font);
}

void Button::setButtonColor(sf::Color color)
{
    setButtonColor(color,color,color);
}

void Button::setButtonColor(sf::Color color, sf::Color hover, sf::Color press)
{
    this->buttonColorSet.color = color;
    this->buttonColorSet.hover = hover;
    this->buttonColorSet.press = press;
}

void Button::setLabelColor(sf::Color color)
{
    setLabelColor(color,color,color);
}


void Button::setLabelColor(sf::Color color, sf::Color hover, sf::Color press)
{
    this->labelColorSet.color = color;
    this->labelColorSet.hover = hover;
    this->labelColorSet.press = press;
}

unsigned int Button::count = 0;
