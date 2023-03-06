#pragma once

#include <SFML/Graphics.hpp>
#include "GravitySource.h"

class Particle
{
private:
	
	sf::Vector2f pos = sf::Vector2f(0.0f, 0.0f);
	sf::Vector2f vel;
	sf::CircleShape s;

public:

	Particle() = default;

	Particle(float pos_x, float pos_y, float vel_x, float vel_y);

	void Render(sf::RenderWindow& window);

	void UpdatePhysics(GravitySource& source);
};

