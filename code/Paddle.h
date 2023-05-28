#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Paddle {
private:
	Vector2f position;

	RectangleShape shape;

	float speed = 1000.0f;
	bool movingRight = false;
	bool movingLeft = false;


public:

	Paddle(float startX, float startY);

	FloatRect getPosition();
	RectangleShape getShape();
	
	void moveLeft();
	void moveRight();
	void stopLeft();
	void stopRight();
	
	void update(Time dt);


};