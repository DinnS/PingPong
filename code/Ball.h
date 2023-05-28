#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball {
private:
	Vector2f position;
	RectangleShape shape;

	float speed = 3500.0f;
	float directionX = .2f;
	float directionY = .2f;


public:
	Ball(float startX, float startY);

	FloatRect getPosition();
	RectangleShape getShape();

	float getXVelocity();

	void reboundSides();
	void reboundPaddleOrTop();

	void reboundBottom();

	void update(Time dt);





};