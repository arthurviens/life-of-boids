#pragma once

#include "myMath/Vec2.hpp"
#include "vector"
// #include "Bird.hpp"
// #include "myMath/utils.hpp"

class Agent{
private:
	Vec2 m_position;
	Vec2 m_velocity;
	double m_bodySize;
	double m_viewAngle;

public:
	Agent() {} // Constructeur avec argument par d�faut
	Agent(Vec2 m_position, Vec2 m_velocity) {}
	~Agent() {} // Destructeur

public:
	Vec2 getPosition();
	Vec2 getVelocity();

	void computePosition();
	void updatePosition();
};