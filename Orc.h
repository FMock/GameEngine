#pragma once
#ifndef ORC_H
#define ORC_H

#include<GL/glew.h>
#include<stdio.h>
#include"DrawUtils.h"
#include"Sprite.h"
#include"Player.h"
#include"Observer.h"

/*
 * Orc.h
 * Frank Mock
 * Orcs are enemies to the Player and are Observers
 * Orcs observer the Player to be notified of the Player's position
 */

class Orc : public Observer, public Sprite{
public:
	Orc();
	Orc(GLuint, float, float, int, int);
	void notify(Player*);
	void draw();
	void update(float);
private:
	GLuint image;
};

#endif