#include"Sprite.h"

// Required to make a default constructor to avoid compile error C2512
Sprite::Sprite(){
	image = glTexImageTGAFile("images/magikarp.tga");
	width = 32;
	height = 32;
	xPos = 32;
	yPos = 32;
}

Sprite::Sprite(GLuint i, int w, int h, int x, int y):image(i), width(w), height(h), xPos(x), yPos(y){}

void Sprite::update(float deltaTime){

}

void Sprite::draw(){
	glDrawSprite(image, width, height, xPos, yPos);
}

int Sprite::getXPos(){
	return xPos;
}

int Sprite::getYPos(){
	return yPos;
}