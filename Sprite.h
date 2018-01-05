#pragma once
#ifndef SPRITE_H
#define SPRITE_H

#include<GL/glew.h>
#include"DrawUtils.h"

class Sprite {
public:
	Sprite();
	Sprite(GLuint, int w, int h, int x, int y);
	void draw();
	void update(float);
protected:
	GLuint image;
	int spriteWidth;
	int spriteHeight;
	int spriteXPos;
	int spriteYPos;
};

#endif