#include "Paddle.h"

Paddle::Paddle(float startX, float startY) {
	position.x = startX;
	position.y = startY;

	shape.setSize(sf::Vector2f(150, 15));
	shape.setPosition(position);
}

FloatRect Paddle::getPosition() {
	return shape.getGlobalBounds();
}

RectangleShape Paddle::getShape() {
	return shape;
}

void Paddle::moveLeft() {
	movingLeft = true;
}

void Paddle::moveRight() {
	movingRight = true;
}

void Paddle::stopLeft() {
	movingLeft = false;
}

void Paddle::stopRight() {
	movingRight = false;
}

void Paddle::update(Time dt) {
	if (movingLeft) {
		position.x -= speed * dt.asSeconds();
	}

	if (movingRight) {
		position.x += speed * dt.asSeconds();
	}

	shape.setPosition(position);
}