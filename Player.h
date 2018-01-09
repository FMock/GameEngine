#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include<GL/glew.h>
#include<vector>
#include"DrawUtils.h"
#include"Observer.h"
#include"Sprite.h"

/*
 * Player.h
 * Frank Mock
 * Player keeps a list of Observers to periodically notify them of changes
 */

class Player : public Sprite{
public:
	Player();
	Player(GLuint, float, float, int, int);
	void draw();
	void update(float);
	void notifyObservers();
	void registerObserver(Observer*);
	void unregisterObserver(Observer*);
	void moveLeft();
	void moveRight();

private:
	GLuint image;
	float speed_x;
	std::vector<Observer*> myObservers;
};

#endif