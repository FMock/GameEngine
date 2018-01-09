#pragma once
#ifndef SPRITE_H
#define SPRITE_H

class Sprite{
public:
	Sprite(void);
	Sprite(float, float, int, int);
	~Sprite(void);
	virtual void draw()=0;
	virtual void update(float)=0;
	int getX()const;
	int getY()const;
	void setX(float);
	void setY(float);
protected:
	float x;
	float change_x;
	float y;
	float change_y;
	int width;
	int height;
};

#endif