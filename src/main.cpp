#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <chrono>
#include <thread>

#define PI 3.14159265f

// desired frame rate
typedef std::chrono::duration<int, std::ratio<1, 60>> frame_duration;



int main() {
    std::cout << "Hello World" << std::endl;


    // Create a window
    sf::RenderWindow window(sf::VideoMode(2400, 1800), "Arrow on Canvas");

    // Define the arrow shape
    sf::ConvexShape arrow;
    arrow.setPointCount(4); // An arrow with 4 points

    // Set the points of the arrow
    arrow.setPoint(0, sf::Vector2f(0,0));   // Point
    arrow.setPoint(1, sf::Vector2f(-50, -200));   // Left
    arrow.setPoint(2, sf::Vector2f(0, -100));    // Center
    arrow.setPoint(3, sf::Vector2f(50, -200));  // Right
    arrow.setOrigin(sf::Vector2f(0, -100));

    // Set the fill color of the arrow
    arrow.setFillColor(sf::Color::Green);

    // Set the position of the arrow
    arrow.setPosition(1200,900);

    // Run the program as long as the window is open
    while (window.isOpen()) {
        
                // Get start time
        auto start_time = std::chrono::steady_clock::now();
        // Get end time
        auto end_time = start_time + frame_duration(1);
        // Here happens the actual update stuff

        

        // Check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window with black color
        window.clear(sf::Color::Black);

        // Draw the arrow
        window.draw(arrow);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            arrow.rotate(5.0f); // Rotate the arrow a little bit every rotation
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            arrow.rotate(-5.0f); // Rotate the arrow a little bit every rotation
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            float amplitude = 15.0f;
            float angle = (arrow.getRotation()) * PI / 180.0f;
            arrow.move(sf::Vector2f(-amplitude*std::sin(angle), amplitude*(std::cos(angle)))); // Rotate the arrow a little bit every rotation
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            float amplitude = 15.0f;
            float angle = (arrow.getRotation()) * PI / 180.0f;
            arrow.move(sf::Vector2f(amplitude*std::sin(angle), -amplitude*(std::cos(angle)))); // Rotate the arrow a little bit every rotation
        }

        std::chrono::duration<float> fsec = (end_time - std::chrono::steady_clock::now());
        std::cout << "Dead Time: " << fsec.count() << std::endl;
        
        // Sleep if necessary
        std::this_thread::sleep_until(end_time);

        // End the current frame
        window.display();
    }

    return 0;
}


/* Possibly helpful functions
        // shape.move(sf::Vector2f(10.0f, 0.0f));
        // shape.rotate(15.0f);
        // sf::Vector2f position = shape.getPosition();
        // shape.setRotation(45.0f);
*/

/* Function for getting individual points
std::size_t pointCount = shape.getPointCount();

    // Vector to store the boundary positions
    std::vector<sf::Vector2f> boundaryPositions;

    // Retrieve each point's position and add to the vector
    for (std::size_t i = 0; i < pointCount; ++i) {
        sf::Vector2f point = shape.getPoint(i);
        boundaryPositions.push_back(point);
    }

    // Print the boundary positions
    for (const auto& position : boundaryPositions) {
        std::cout << "Point: (" << position.x << ", " << position.y << ")\n";
    }
*/

/*
#include <chrono>
#include <thread>
Sleep function: std::this_thread::sleep_for(std::chrono::milliseconds(500));
*/