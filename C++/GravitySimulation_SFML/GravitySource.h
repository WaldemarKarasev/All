#pragma once
#include <SFML/Graphics.hpp>

class GravitySource
{
private:
	sf::Vector2f pos;
	float strength;

	sf::CircleShape s;

public:
	GravitySource(float pos_x, float pos_y, float strength);

	void Render(sf::RenderWindow& window);
	
	// Getters for patricles
	sf::Vector2f get_pos();
	float getStrength();
};

