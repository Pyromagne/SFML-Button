#include "sfml_button.hpp"

////////////////////////////////////////////////////////////
///
/// @category Ellipse Button methods
///
////////////////////////////////////////////////////////////

EllipseButton::EllipseButton(float radius = 0)
{   //Constructor
    count++;
    std::cout<<"Button Contructor Called"<<std::endl;
    this->button.setRadius(radius);
    this->buttonRect = this->button.getLocalBounds();
}

////////////////////////////////////////////////////////////

EllipseButton::EllipseButton(float radius = 0, const sf::Vector2f position = sf::Vector2f(0, 0))
{
    //Constructor
    count++;
    std::cout<<"Button Contructor Called"<<std::endl;
    this->button.setRadius(radius);
    this->button.setPosition(position);
    this->buttonPos = position;
    this->buttonRect = this->button.getLocalBounds();
}

////////////////////////////////////////////////////////////

EllipseButton::EllipseButton(const sf::Vector2f position = sf::Vector2f(0, 0), bool autoSize = false)
{   //Constructor
    count++;
    std::cout<<"Button Contructor Called"<<std::endl;
    this-> autoSize = autoSize;
    this->button.setPosition(position);
    this->buttonPos = position;
}

////////////////////////////////////////////////////////////

EllipseButton::~EllipseButton()
{   //Deconstructor
    count--;
    std::cout<<"Button Deconstructor Called"<<std::endl;
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
            button.setFillColor(defaultHovered);
        }
        else button.setFillColor(sf::Color::White);

        if (isPressed)
        {
            button.setFillColor(defaultPressed);
        }
    }
    else
    {
        button.setFillColor(defaultPressed);
    }
}

////////////////////////////////////////////////////////////

void EllipseButton::draw(sf::RenderWindow& window)
{
    window.draw(button);
    window.draw(buttonLabel);
}

////////////////////////////////////////////////////////////

void EllipseButton::setButtonLable(std::string label, const sf::Color& color, float charSize)
{
    this->buttonLabel.setString(label);
    this->buttonLabel.setCharacterSize(charSize);
    this->buttonLabel.setFillColor(color);
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

