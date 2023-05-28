#include "Ball.h"

Ball::Ball(float startX, float startY) {
	position.x = startX;
	position.y = startY;

	shape.setSize(sf::Vector2f(30,30));
	shape.setPosition(position);
}

FloatRect Ball::getPosition() {
	return shape.getGlobalBounds();
}

RectangleShape Ball::getShape() {
	return shape;
}

float Ball::getXVelocity() {
	return directionX;
}

void Ball::reboundSides() {
	directionX = -directionX;
}

void Ball::reboundPaddleOrTop() {
	directionY = -directionY;
}

void Ball::reboundBottom() {
	position.x = 1920 / 2;
	position.y = shape.getSize().x;
	//directionY = -directionY;
}

void Ball::update(Time dt) {
	position.x += directionX * speed * dt.asSeconds();
	position.y += directionY * speed * dt.asSeconds();
	shape.setPosition(position);
}