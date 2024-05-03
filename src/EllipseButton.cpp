#include "../include/Button.hpp"
#include "../include/EllipseButton.hpp"

////////////////////////////////////////////////////////////
///
/// @category Ellipse Button methods
///
////////////////////////////////////////////////////////////

EllipseButton::EllipseButton(float radius = 0,  const sf::Vector2f position = sf::Vector2f(0, 0))
{
    count++;
    this->button.setRadius(radius);
    this->button.setPosition(position);
    this->buttonPos = position;
    this->buttonRect = this->button.getLocalBounds();
    this->button.setFillColor(defaultColor);
}

////////////////////////////////////////////////////////////

EllipseButton::EllipseButton(sf::Font& font, float radius = 0, const sf::Vector2f position = sf::Vector2f(0, 0))
{
    count++;
    this->button.setRadius(radius);
    this->button.setPosition(position);
    this->buttonPos = position;
    this->buttonRect = this->button.getLocalBounds();
    this->button.setFillColor(defaultColor);

    this->buttonLabel.setFont(font);
    this->label = "Button "+ std::to_string(count);
    this->setButtonLabel(25.f, label);
}

////////////////////////////////////////////////////////////

EllipseButton::EllipseButton(sf::Font& font, bool autoSize = false, const sf::Vector2f position = sf::Vector2f(0, 0))
{
    count++;
    this-> autoSize = autoSize;
    this->button.setPosition(position);
    this->buttonPos = position;
    this->button.setFillColor(defaultColor);

    this->buttonLabel.setFont(font);
    this->label = "Button "+ std::to_string(count);
    this->setButtonLabel(25.f, label);
}

////////////////////////////////////////////////////////////

EllipseButton::~EllipseButton()
{
    count--;
}

////////////////////////////////////////////////////////////

void EllipseButton::getButtonStatus(sf::RenderWindow& window, sf::Event& event)
{
    this->mousePosWindow = sf::Mouse::getPosition(window);
    this->mousePosView = window.mapPixelToCoords(this->mousePosWindow);

    this->isHover = false;
    this->isPressed = false;

    if (isActive)
    {
        button.setFillColor(buttonColorSet.color);
        buttonLabel.setFillColor(labelColorSet.color);
        if(button.getGlobalBounds().contains(this->mousePosView))
        {
            this->isHover = true;
        }

        if(button.getGlobalBounds().contains(this->mousePosView))
        {
            if(event.type == sf::Event::MouseButtonReleased)
            {
                this->isPressed = true;
            }
        }

        //I am not sure if it is best to implement this inside a class
        if (isHover)
        {
            button.setFillColor(buttonColorSet.hover);
            buttonLabel.setFillColor(labelColorSet.hover);
        }
        else
        {
            button.setFillColor(buttonColorSet.color);
        }

        if(button.getGlobalBounds().contains(this->mousePosView))
        {
            if (event.type == sf::Event::MouseButtonPressed)
            {
                button.setFillColor(buttonColorSet.press);
                buttonLabel.setFillColor(labelColorSet.press);
            }
        }
    }
    else
    {
        button.setFillColor(disabled);
    }
}

////////////////////////////////////////////////////////////

void EllipseButton::draw(sf::RenderWindow& window)
{
    window.draw(button);

    if (isLabelVisible)
    {
        window.draw(buttonLabel);
    }
}

////////////////////////////////////////////////////////////

void EllipseButton::setButtonLabel(float charSize, std::string label)
{
    this->buttonLabel.setString(label);
    this->buttonLabel.setCharacterSize(charSize);
    this->buttonLabel.setFillColor(labelColorSet.color);
    this->label = label;


    this->labelRect = this->buttonLabel.getLocalBounds();

    if(autoSize)
    {
        button.setRadius(labelRect.width / 1.5f);

        this->buttonRect = this->button.getLocalBounds();

        this->buttonLabel.setOrigin(this->labelRect.width/2.0f,
                                        this->labelRect.height/2.0f);

        this->buttonLabel.setPosition(this->buttonPos.x + (this->buttonRect.width / 2.0f),
                                    this->buttonPos.y + (this->buttonRect.height / 2.5f));
    }
    else
    {
        this->buttonLabel.setOrigin(this->labelRect.width/2.0f,
                                        this->labelRect.height/2.0f);

        this->buttonLabel.setPosition(this->buttonPos.x + (this->buttonRect.width / 2.0f),
                                    this->buttonPos.y + (this->buttonRect.height / 3.0f));
    }

}

////////////////////////////////////////////////////////////

void EllipseButton::setButtonLabel(float charSize)
{
    setButtonLabel(charSize, this->label);
}

