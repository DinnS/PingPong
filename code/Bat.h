#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Bat {
private:
	Vector2f m_Position;

	RectangleShape shape;
	float speed = 1000.0f;
	bool movingRight = false;
	bool movingLeft = false;


public:

	Bat(float startX, float startY);

	FloatRect getPosition();
	RectangleShape getShape();
	
	void moveLeft();
	void moveRight();
	void stopLeft();
	void stopRight();
	
	void update(Time dt);


};