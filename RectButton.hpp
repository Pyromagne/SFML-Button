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

    RectButton(const sf::Vector2f);
    RectButton(const sf::Vector2f, const sf::Vector2f);
    RectButton(const sf::Vector2f, bool autoSize);

    ~RectButton();

    void getButtonStatus(sf::RenderWindow&, sf::Event&);
    void draw(sf::RenderWindow&);
    void setButtonLable(std::string, const sf::Color&, float);

    sf::RectangleShape button;

    private:
    sf::FloatRect buttonRect;
};

#endif // RECTBUTTON_HPP_INCLUDED
