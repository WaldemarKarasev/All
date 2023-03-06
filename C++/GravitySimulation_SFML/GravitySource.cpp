#include "GravitySource.h"

GravitySource::GravitySource(float pos_x, float pos_y, float strength)
{
	pos.x = pos_x;
	pos.y = pos_y;
	this->strength = strength;

	s.setPosition(pos);
	s.setFillColor(sf::Color::Yellow);
	s.setRadius(10);

}

void GravitySource::Render(sf::RenderWindow& window)
{
	window.draw(s);
}


sf::Vector2f GravitySource::get_pos()
{
	return pos;
}

float GravitySource::getStrength()
{
	return strength;
}

