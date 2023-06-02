#include "Ball.h"
#include "math.h"

Ball::Ball(float startX, float startY) {
	position.x = startX;
	position.y = startY;

	shape.setRadius(25.f);
	shape.setPosition(position);
}

FloatRect Ball::getPosition() {
	return shape.getGlobalBounds();
}

CircleShape Ball::getShape() {
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

void Ball::reboundPaddle(FloatRect paddlePosition) {
	float centerBall = getPosition().left + (getPosition().width / 2);
	float centerPaddle = paddlePosition.left + (paddlePosition.width / 2);
	float pointCollision = centerBall - centerPaddle;

	directionX = cos(pointCollision);
	directionY = -directionY;
}

void Ball::reboundBottom() {
	position.x = 1920 / 2;
	position.y = shape.getRadius() * 3;
	//directionY = -directionY;
}

void Ball::update(Time dt) {
	position.x += directionX * speed * dt.asSeconds();
	position.y += directionY * speed * dt.asSeconds();
	shape.setPosition(position);
}