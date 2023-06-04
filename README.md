# SFML Button Library

The SFML Button Library is a C++ library built using the SFML Graphics Library. It is designed to help developers create interactive and customizable button elements for their SFML-based projects. The library provides two button classes: RectButton and EllipseButton.

## API Documentation
### (Documentation is outdated it will be updated soon)

The library provides a `Button` base class and a `RectButton` derived class:

### `Button`

The `Button` class is a pure virtual class that defines the interface for all buttons in the library. It provides the following pure virtual methods:

- `getButtonStatus(sf::RenderWindow&, sf::Event&)`: gets the current status of the button (hovered, pressed, etc.) based on user interaction with the button.
- `draw(sf::RenderWindow&)`: draws the button on a given window.
- `setButtonFont(sf::Font&)`: sets the font of the button label.
- `setButtonLabel(const sf::Color&, float, std::string)`: sets the text, color, and size of the button label.

The `Button` class also provides the following member variables:

- `isHover`: a boolean indicating whether the button is currently being hovered over by the user.
- `isPressed`: a boolean indicating whether the button is currently being pressed by the user.
- `isActive`: a boolean indicating whether the button is currently active or not.
- `autoSize`: a boolean indicating whether the button should automatically resize to fit its label.
- `buttonLabel`: an `sf::Text` object representing the label of the button.
- `mousePosWindow`: an `sf::Vector2i` representing the current position of the mouse on the window.
- `mousePosView`: an `sf::Vector2f` representing the current position of the mouse on the view.
- `buttonPos`: an `sf::Vector2f` representing the position of the button.
- `labelRect`: an `sf::FloatRect` representing the rectangle bounding the button label.
- `label`: a string representing the text of the button label.

### `RectButton`

The `RectButton` class is a derived class of `Button` that provides a rectangular button implementation. It provides the following methods:

- `RectButton(const sf::Vector2f)`: constructs a rectangular button object with the given size.
- `RectButton(const sf::Vector2f, const sf::Vector2f)`: constructs a rectangular button object with the given size and position.
- `RectButton(const sf::Vector2f, bool autoSize)`: constructs a rectangular button object with the given position, and optionally automatically sizes the button to fit its label.

The `RectButton` class also provides the following member variables:

- `button`: an `sf::RectangleShape` representing the rectangular shape of the button.
- `buttonRect`: an `sf::FloatRect` representing the rectangle bounding of the button.

### `EllipseButton`

The `EllipseButton` class is a derived class of `Button` that provides a elliptical button implementation. It provides the following methods:

- `EllipseButton(float radius)`: construct a circular button object with the given radius.
- `EllipseButton(float radius, const sf::Vector2f)`: construct a circular button object with the given radius and position.
- `EllipseButton(const sf::Vector2f, bool autoSize)`: construct a circular button object with the given position, and optionally automatically sizes the button to fit its label.

The `EllipseButton` class also provides the following member variables:

- `button`:an `sf::CircleShape` representing the circular shape of the button.
- `buttonRect`: an `sf::FloatRect` representing the rectangle bounding of the button.

## Example Usage

```c++
#include <SFML/Graphics.hpp>
#include "sfml_button.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Button Library");

    RectButton button(sf::Vector2f(150.f, 50.f), sf::Vector2f(325.f, 275.f));
    button.setButtonLabel(sf::Color::Black, 24.f, "Click me!");
    button.setButtonFont(buttonFont);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            button.getButtonStatus(window, event);

            if (event.type == sf::Event::Closed)
                window.close();

            if (button.isPressed)
                std::cout << "Button was pressed!" << std::endl;
        }

        window.clear(sf::Color::White);

        button.draw(window);

        window.display();
    }

    return 0;
}
```

### Limitations
SFML Button Library is a useful tool for developers looking to create customizable button elements for their SFML projects. However, it is still a work in progress, and the developers need to fix some of the limitations before it can be considered a complete library.
