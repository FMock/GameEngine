#pragma once
#ifndef GAMEDATA_H
#define GAMEDATA_H

class GameData{
public:
	// static members made available to other game objects
	static enum gameState{START, PLAY, PAUSE, END};
	static void setCurrentGameState(int);

private:
	GameData(){}
	static int currentGameState;
};

#endif