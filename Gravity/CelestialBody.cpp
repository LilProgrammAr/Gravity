#include "CelestialBody.h"
#include "CelestialBody.h"

#include <cmath>

CelestialBody::CelestialBody() :
	_mass(0),
	_radius(1),
	_acceleration(sf::Vector2f(0.0, 0.0))
{
	_sprite.setPointCount(50);
	_sprite.setPosition(sf::Vector2f(0, 0));
	_sprite.setRadius(_radius);
}

CelestialBody::CelestialBody(float mass, bool fixed) :
	_mass(mass),
	_radius(MASS_RATIO * sqrt(mass)),
	_fixed(fixed),
	_acceleration(sf::Vector2f(0.0, 0.0))
{
	_sprite.setPointCount(50);
	_sprite.setPosition(sf::Vector2f(0, 0));
	_sprite.setRadius(_radius);
}

void CelestialBody::setRadius(float radius)
{
	_radius = radius;
	_sprite.setRadius(radius);
}

void CelestialBody::setMass(float mass)
{
	_mass = mass;
	setRadius(MASS_RATIO * sqrt(mass));
}

void CelestialBody::setPosition(sf::Vector2f position)
{
	_sprite.setPosition(position - sf::Vector2f(_sprite.getRadius(),
		_sprite.getRadius()));
}

void CelestialBody::setPosition(float x, float y)
{
	_sprite.setPosition(x - _sprite.getRadius(), y - _sprite.getRadius());
}

void CelestialBody::setAcceleration(sf::Vector2f acceleration)
{
	_acceleration = acceleration;
}

void CelestialBody::setAcceleration(float x, float y)
{
	_acceleration = sf::Vector2f(x, y);
}

void CelestialBody::addMass(int mass)
{
	_mass += mass;
	float delta_radius = MASS_RATIO * sqrt(_mass) - _radius;
	_radius += delta_radius;
	setPosition(getPosition() - sf::Vector2f(delta_radius, delta_radius));
	_sprite.setRadius(_radius);
}
// ?
void CelestialBody::move(sf::Vector2f acceleration)
{
	if (!_fixed)
		_acceleration += acceleration;
	//else
	//        ??
}

// same ^ \/
void CelestialBody::move(int x, int y)
{
	if (!_fixed)
		_acceleration += sf::Vector2f((float)x, (float)y);
}

sf::Vector2f CelestialBody::getPosition() const
{
	return _sprite.getPosition() + sf::Vector2f(_sprite.getRadius(), _sprite.getRadius());
}

sf::Vector2f CelestialBody::getAcceleration() const
{
	return _acceleration;
}

float CelestialBody::getMass() const
{
	return _mass;
}

float CelestialBody::getRadius() const
{
	return _radius;
}

bool CelestialBody::isFixed() const
{
	return _fixed;
}


void CelestialBody::draw(sf::RenderWindow* target)
{
	target->draw(_sprite);
}

// same
void CelestialBody::update()
{
	if (!_fixed)
		_sprite.move(_acceleration);
}
