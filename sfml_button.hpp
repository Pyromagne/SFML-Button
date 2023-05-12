////////////////////////////////////////////////////////////
///
/// SFML BUTTON LIBRARY
/// Copyright (c) 2023 Pyromagne
///
////////////////////////////////////////////////////////////

#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED
#include <SFML/Graphics.hpp>
#include <iostream>

const sf::Color defaultHovered = sf::Color(191, 191, 191);
const sf::Color defaultPressed = sf::Color(153, 153, 153);

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
};

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

////////////////////////////////////////////////////////////
///
/// @brief Make a circle button
///
////////////////////////////////////////////////////////////

class EllipseButton: public Button
{
    public:

    EllipseButton(float radius);
    EllipseButton(float radius, const sf::Vector2f);
    EllipseButton(const sf::Vector2f, bool autoSize);

    ~EllipseButton();

    void getButtonStatus(sf::RenderWindow&, sf::Event&);
    void draw(sf::RenderWindow&);
    void setButtonLable(std::string, const sf::Color&, float);

    sf::CircleShape button;

    private:
    sf::FloatRect buttonRect;
};




#endif // BUTTON_HPP_INCLUDED
