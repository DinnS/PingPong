	#include "Paddle.h"
#include "Ball.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>



int main() {
	// Setup window
	VideoMode vm(1920, 1080);
	RenderWindow window(vm, "Ping Pong", Style::Fullscreen);

	
	
	// Setup text
	Font font;
	font.loadFromFile("../fonts/DS-DIGI.TTF");
	

	Text hudLives;
	hudLives.setFont(font);
	hudLives.setCharacterSize(75);
	hudLives.setFillColor(Color::White);
	hudLives.setPosition(20, 20);

	Text hudScore;
	hudScore.setFont(font);
	hudScore.setCharacterSize(75);
	hudScore.setFillColor(Color::White);
	hudScore.setPosition(850, 20);
	

	// Init class
	Paddle paddle(1920 / 2, 1080 - 100);
	
	Ball ball(1920 / 2, 0);

	// General variables
	int score = 0;
	int lives = 3;



	// FPS
	Clock clock;


	// Game loop
	while (window.isOpen()) {

		/**********************
		Handle the player input
		**********************/

		Event event;


		// Close window
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}

		}

		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
		}


		// Movement player
		if ((Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left)) && (paddle.getPosition().left > 0)) {
			paddle.moveLeft();
		}
		else {
			paddle.stopLeft();
		}


		if ((Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right)) && (paddle.getPosition().left + paddle.getPosition().width < window.getSize().x)) {
			paddle.moveRight();
		}
		else {
			paddle.stopRight();
		}


		/**********************
		Update
		**********************/

		// Update fps
		Time dt = clock.restart();


		// Update class
		paddle.update(dt);
		ball.update(dt);


		// Update text
		

		std::stringstream strLives;
		strLives << "Lives : " << lives;
		hudLives.setString(strLives.str());


		std::stringstream strScore;
		strScore << "Score : " << score;
		hudScore.setString(strScore.str());

		// Update general function
		if (ball.getPosition().top > window.getSize().y) {
			ball.reboundBottom();	

			lives--;

			if (lives < 1) {
				score = 0;

				lives = 3;
			}
		}

		if (ball.getPosition().top < 0) {
			ball.reboundPaddleOrTop();

			score++;
		}

		if (ball.getPosition().left < 0 || ball.getPosition().left + ball.getPosition().width > window.getSize().x ) {
			ball.reboundSides();
		}

		if (ball.getPosition().intersects(paddle.getPosition())) {
			//ball.reboundPaddle(paddle.getPosition());
			ball.reboundPaddleOrTop();
		}

		/**********************
		Draw
		**********************/

		// Draw clean window
		window.clear();



		// Draw hud
		window.draw(hudLives);
		window.draw(hudScore);


		// Draw class
		window.draw(paddle.getShape());
		window.draw(ball.getShape());

		// Draw window
		window.display();


	}


	return 0;
}