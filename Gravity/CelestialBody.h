#pragma once 
#ifndef CLASS_CELESTIALBODDY_H
#define CLASS_CELESTIALBODDY_H

#include <SFML\Graphics.hpp>
#include "Core\core.h"

class CelestialBody
{
private:
	float _mass;
	float _radius;

	bool _fixed;

	sf::CircleShape _sprite;
	sf::Vector2f _acceleration;

public:
	CelestialBody();
	explicit CelestialBody(float mass, bool fixed = false);
	~CelestialBody() = default;

	void setRadius(float radius);
	void setMass(float mass);
	void setPosition(sf::Vector2f position);
	void setPosition(float x, float y);
	void setAcceleration(sf::Vector2f acceleration);
	void setAcceleration(float x, float y);

	void addMass(int mass);

	void move(sf::Vector2f direction);
	void move(int x, int y);

	sf::Vector2f getPosition() const;
	sf::Vector2f getAcceleration() const;

	float getMass() const;
	float getRadius() const;
	bool isFixed() const;

	void draw(sf::RenderWindow* target);
	void update();
};

#endif //CLASS_CELESTIALBODDY_H
