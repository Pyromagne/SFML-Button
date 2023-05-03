# SFML Button Library

The SFML Button Library is a C++ library built using the SFML Graphics Library. It is designed to help developers create interactive and customizable button elements for their SFML-based projects. The library provides two button classes: RectButton and EllipseButton.

## Button Class

The `Button` class is the base class for both rectangular and circular buttons. It defines the common properties and functions that the buttons share. The class has the following public functions:

- `void getButtonStatus(sf::RenderWindow&, sf::Event&)`: This function updates the status of the button based on the mouse events.
- `void draw(sf::RenderWindow&)`: This function draws the button on the screen.
- `void setButtonLable(std::string, const sf::Color&, float)`: This function sets the label of the button, the text color, and the character size.
- `void setButtonFont(sf::Font&)`: This function sets the font of the button.

The class also has the following public properties:

- `bool isHover`: This property is true if the mouse is hovering over the button.
- `bool isPressed`: This property is true if the button is pressed.
- `bool autoSize`: This property is true if the button should be automatically resized based on the label size.
- `bool enabled`: This property is true if the button can be pressed by the user.

## RectButton

The RectButton class is a subclass of the Button class, which provides the base functionality for the button. The RectButton class allows you to create rectangular buttons with customizable size and position. The class provides methods for detecting the button's status (i.e., whether it is hovered over or pressed), drawing the button to the screen, and setting the button's label and font.

The `RectButton` class is a rectangular button that inherits from the `Button` class. It has the following constructors:

- `RectButton(const sf::Vector2f)`: This constructor creates a button with a specified size.
- `RectButton(const sf::Vector2f, const sf::Vector2f)`: This constructor creates a button with a specified size and position.
- `RectButton(bool autoSize, const sf::Vector2f)`: This constructor creates a button with a specified position and an auto-size option.

The class also has the following public function:

- `void getButtonStatus(sf::RenderWindow&, sf::Event&)`: This function updates the status of the button based on the mouse events.
- `void draw(sf::RenderWindow&)`: This function draws the button on the screen.
- `void setButtonLable(std::string, const sf::Color&, float)`: This function sets the label of the button, the text color, and the character size.
- `void setButtonFont(sf::Font&)`: This function sets the font of the button.

## EllipseButton

The EllipseButton class is another subclass of the Button class. This class allows you to create circular buttons with customizable size and position. The class provides methods for detecting the button's status and drawing the button to the screen.

The `EllipseButton` class is a circular button that inherits from the `Button` class. It has the following constructors:

- `EllipseButton(float radius)`: This constructor creates a button with a specified radius.
- `EllipseButton(float radius, const sf::Vector2f)`: This constructor creates a button with a specified radius and position.

The class also has the following public function:

- `void getButtonStatus(sf::RenderWindow&, sf::Event&)`: This function updates the status of the button based on the mouse events.
- `void draw(sf::RenderWindow&)`: This function draws the button on the screen.

The class also has the following public properties:

- `sf::CircleShape button`: This property is the circle shape of the button.

Sure, here's an example usage of the `RectButton` class:

## Example Usage

```c++
#include <SFML/Graphics.hpp>
#include "sfml_button.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Button Library");

    RectButton button(sf::Vector2f(150.f, 50.f), sf::Vector2f(325.f, 275.f));
    button.setButtonLable("Click me!", sf::Color::Black, 24.f);
    button.setButtonFont(buttonFont);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            button.getButtonStatus(window, event);

            if (button.isPressed)
            {
                std::cout << "Button was pressed!" << std::endl;
            }
        }

        window.clear(sf::Color::White);
        button.draw(window);
        window.display();
    }

    return 0;
}
```
### Limitations
The current implementation of the library has a few limitations. For example, the library does not implement the `enabled` feature, which allows the developer to disable the button and prevent it from being pressed by the user. Also, the `autoSize` feature does not work properly and needs to be fixed.

Like the RectButton class, the EllipseButton class has the same limitations. The library does not implement the `enabled` feature, and the `autoSize` feature needs to be fixed.

Overall, the SFML Button Library is a useful tool for developers looking to create customizable button elements for their SFML projects. However, it is still a work in progress, and the developers need to fix some of the limitations before it can be considered a complete library.
