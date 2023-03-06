#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>


#include "GravitySource.h"
#include "Particle.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 1000), "SFML works!");
    
    /*
    // array of balls
    sf::CircleShape* bunch_of_balls = new sf::CircleShape[20];
    // point of the 1st ball
    float posX = 0.0f;
    float posY = 0.0f;
    float dist = 10;
    int col = 0;
    int row = 0;

    for (size_t i = 1; i <= 20; i++)
    {
        
        posX = dist*col;
        posY = dist*row;
        bunch_of_balls[i-1] = sf::CircleShape(2);
        bunch_of_balls[i-1].setPosition(posX, posY);
    
        std::cout << "PosX = " << posX << "; PosY = " << posY << std::endl;
        std::cout << "index(" << col << ", " << row << ")" << std::endl;

        ++col;

        if (i % 5 == 0)
        {
            col = 0;
            ++row;
        }
    }
    */
    std::vector<Particle> bunch_of_particle;
    float posX = 500.0f;
    float posY = 400.0f;
    float dist = 5.0f;
    int col = 0;
    int row = 0;
    for (size_t i = 1; i <= 400; i++)
    {

        posX = dist * col + 400;
        posY = dist * row + 400;
        bunch_of_particle.push_back(Particle(dist * col + 600, dist * row + 100, 0.15, 0));

        //std::cout << "PosX = " << posX << "; PosY = " << posY << std::endl;
        //std::cout << "index(" << col << ", " << row << ")" << std::endl;

        ++col;

        if (i % 20 == 0)
        {
            col = 0;
            ++row;
        }
    }

    GravitySource source1(400.0, 500.0, 10.0);
    GravitySource source2(1200.0, 500.0, 20.0);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
      
        for (size_t i = 0; i < 400; i++)
        {
            bunch_of_particle[i].Render(window);
            bunch_of_particle[i].UpdatePhysics(source1);
            bunch_of_particle[i].UpdatePhysics(source2);
        }

            
        source1.Render(window);
        source2.Render(window);
        window.display();
    }

    return 0;
}