#include"Sprite.h"

// Required to make a default constructor to avoid compile error C2512
Sprite::Sprite(){
	image = glTexImageTGAFile("images/magikarp.tga");
	spriteWidth = 32;
	spriteHeight = 32;
	spriteXPos = 32;
	spriteYPos = 32;
}

Sprite::Sprite(GLuint i, int w, int h, int x, int y):image(i), spriteWidth(w), spriteHeight(h), spriteXPos(x), spriteYPos(y){}

void Sprite::update(float deltaTime){

}

void Sprite::draw(){
	glDrawSprite(image, spriteWidth, spriteHeight, spriteXPos, spriteYPos);
}