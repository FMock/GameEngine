#include"Player.h"

// Required to make a default constructor to avoid compile error C2512
Player::Player() : Sprite(){
	image = glTexImageTGAFile("images/magikarp.tga");
	speed_x = 50.0;
}

Player::Player(GLuint i, float xPos, float yPos, int w, int h):image(i), Sprite(xPos, yPos, w, h){
	speed_x = 50.0;
}

void Player::moveLeft(){
	change_x = -speed_x;
}

void Player::moveRight(){
	change_x = speed_x;
}

void Player::update(float deltaTime){
	x += change_x * deltaTime;
	notifyObservers();
}

void Player::draw(){
	glDrawSprite(image, x, y, width, height);
}

// Notify all observers of Player info
void Player::notifyObservers(){
	for(int i = 0; i < myObservers.size(); i++){
		myObservers.at(i)->notify(this);
	}
}

// Add observers to Player's list of observers
void Player::registerObserver(Observer *observer){
	myObservers.push_back(observer);
}

// Remove observer from Player's list of observers
void Player::unregisterObserver(Observer *observer){
	for(int i = 0; i < myObservers.size(); i++){
		if(myObservers.at(i)==observer){
			myObservers.erase(myObservers.begin()+i);
			return;
		}
	}
}