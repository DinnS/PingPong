#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball {
private:
	Vector2f position;
	CircleShape shape;

	float speed = 550.0f;
	float directionX = 1.f;
	float directionY = 1.f;


public:
	Ball(float startX, float startY);

	FloatRect getPosition();
	CircleShape getShape();

	float getXVelocity();

	void reboundSides();
	void reboundPaddleOrTop();


	void reboundBottom();

	void update(Time dt);





};