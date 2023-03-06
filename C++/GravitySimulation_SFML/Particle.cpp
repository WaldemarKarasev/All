#include "Particle.h"
#include "GravitySource.h"
#include <cmath>


Particle::Particle(float pos_x, float pos_y, float vel_x, float vel_y)
{
	pos.x = pos_x;
	pos.y = pos_y;

	vel.x = vel_x;
	vel.y = vel_y;

	s.setPosition(pos);
	s.setFillColor(sf::Color::White);
	s.setRadius(1);
}

void Particle::Render(sf::RenderWindow& window)
{
	s.setPosition(pos);
	window.draw(s);
}

void Particle::UpdatePhysics(GravitySource& source)
{
	float distance_x = source.get_pos().x - pos.x;
	float distance_y = source.get_pos().y - pos.y;

	float distance = sqrt(distance_x * distance_x + distance_y * distance_y);

	float inverse_distance = 1.f / distance;

	float norm_x = inverse_distance * distance_x;
	float norm_y = inverse_distance * distance_y;

	float inverse_square_dropoff = inverse_distance * inverse_distance;

	float acceleration_x = norm_x * source.getStrength() * inverse_square_dropoff;
	float acceleration_y = norm_y * source.getStrength() * inverse_square_dropoff;

	vel.x += acceleration_x;
	vel.y += acceleration_y;

	pos.x += vel.x;
	pos.y += vel.y;

}
