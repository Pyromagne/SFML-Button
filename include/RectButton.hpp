////////////////////////////////////////////////////////////
// MIT License
//
// Copyright (c) 2024 Pyromagne
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

#ifndef RECTBUTTON_HPP_INCLUDED
#define RECTBUTTON_HPP_INCLUDED

////////////////////////////////////////////////////////////
// HEADERS
////////////////////////////////////////////////////////////

#include <SFML/Graphics.hpp>
#include <iostream>

////////////////////////////////////////////////////////////
///
/// @brief make a rectangle button
///
////////////////////////////////////////////////////////////

class RectButton: public Button
{
    public:

        RectButton(                const sf::Vector2f size, const sf::Vector2f position);
        RectButton(sf::Font& font, const sf::Vector2f size, const sf::Vector2f position);
        RectButton(sf::Font& font, bool autoSize,           const sf::Vector2f position);

        ~RectButton();

        void getButtonStatus(sf::RenderWindow& window, sf::Event& event);
        void draw(sf::RenderWindow& window);
        void setButtonLabel(float charSize, std::string label);
        void setButtonLabel(float charSize);

        sf::RectangleShape button;

    //end of public

    private:

        sf::FloatRect buttonRect;

    //end of private
};

#endif // RECTBUTTON_HPP_INCLUDED
