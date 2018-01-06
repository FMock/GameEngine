#include"GameData.h"

// Initialize static members
int GameData::currentGameState = GameData::START;

// Change the current game state
void GameData::setCurrentGameState(int s){
	if(s >= GameData::gameState::START && s <= GameData::gameState::END){
		GameData::currentGameState = s;
	}
}