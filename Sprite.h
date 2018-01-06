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
	int getXPos();
	int getYPos();
protected:
	GLuint image;
	int width;
	int height;
	int xPos;
	int yPos;
};

#endif