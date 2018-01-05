#define SDL_MAIN_HANDLED
#include<SDL.h>
#include<GL/glew.h>
#include<stdio.h>
#include<string>
#include<iostream>
#include<assert.h>
#include"DrawUtils.h"
#include"KeyInfo.h"
#include"Sprite.h"
#include<vector>

/*
	main.cpp
	
	Program Name - main.cpp for GameEngine
	Author - Frank Mock
	Project Start Date - 12/31/2017
*/


// Set this to true to make the game loop exit.
char shouldExit = 0;

// The previous frame's keyboard state.
unsigned char kbPrevState[SDL_NUM_SCANCODES] = { 0 };

// The current frame's keyboard state.
const unsigned char* kbState = NULL;

// To get keyboard state
//const Uint8 *keyState;

// To regulate frame rate
int previousTime = 0;
int currentTime = 0;
float deltaTime = 0.0f;
float noKeyPressTime = 0.0f;

// Sprites
Sprite player;

int main(void)
{
	// Initialize SDL.
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "Could not initialize SDL. ErrorCode=%s\n", SDL_GetError());
		return 1;
	}

	// Create the window and OpenGL context.
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_Window* window = SDL_CreateWindow(
		"Game Engine",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		800, 600,
		SDL_WINDOW_OPENGL);
	if (!window) {
		fprintf(stderr, "Could not create window. ErrorCode=%s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	}
	SDL_GL_CreateContext(window);

	// Make sure we have a recent version of OpenGL.
	GLenum glewError = glewInit();
	if (glewError != GLEW_OK) {
		fprintf(stderr, "Could not initialize glew. ErrorCode=%s\n", glewGetErrorString(glewError));
		SDL_Quit();
		return 1;
	}
	if (GLEW_VERSION_2_0) {
		fprintf(stderr, "OpenGL 2.0 or greater supported: Version=%s\n",
			glGetString(GL_VERSION));
	}
	else {
		fprintf(stderr, "OpenGL max supported version is too low.\n");
		SDL_Quit();
		return 1;
	}

	// Setup OpenGL state.
	glViewport(0, 0, 800, 600);
	glMatrixMode(GL_PROJECTION);
	glOrtho(0, 800, 600, 0, 0, 100);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	player = Sprite(glTexImageTGAFile("images/magikarp.tga"), 32, 32, 128, 128);



	//********** GAME LOOP *************************************************************
	while (!shouldExit) {
		kbState = SDL_GetKeyboardState(NULL);// We want status of all the keys

		// Find out how many seconds have past since last loop iteration
		previousTime = currentTime;
		currentTime = SDL_GetTicks();
		deltaTime = (currentTime - previousTime) / 1000.0f;


		assert(glGetError() == GL_NO_ERROR);
		memcpy(kbPrevState, kbState, sizeof(kbPrevState));

		
		// Handle OS message pump.
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				shouldExit = 1;
			}
		}


		// Take action if any keys are pressed. check SDL SCANCODES https://wiki.libsdl.org/SDL_Scancode
		if(kbState[SDL_SCANCODE_A] && !kbPrevState[SDL_SCANCODE_A]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("A");
		}
		else if(kbState[SDL_SCANCODE_B] && !kbPrevState[SDL_SCANCODE_B]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("B");
		}
		else if(kbState[SDL_SCANCODE_C] && !kbPrevState[SDL_SCANCODE_C]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("C");
		}
		else if(kbState[SDL_SCANCODE_D] && !kbPrevState[SDL_SCANCODE_D]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("D");
		}
		else if(kbState[SDL_SCANCODE_E] && !kbPrevState[SDL_SCANCODE_E]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("E");
		}
		else if(kbState[SDL_SCANCODE_F] && !kbPrevState[SDL_SCANCODE_F]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("F");
		}
		else if(kbState[SDL_SCANCODE_G] && !kbPrevState[SDL_SCANCODE_G]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("G");
		}
		else if(kbState[SDL_SCANCODE_H] && !kbPrevState[SDL_SCANCODE_H]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("H");
		}
		else if(kbState[SDL_SCANCODE_I] && !kbPrevState[SDL_SCANCODE_I]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("I");
		}
		else if(kbState[SDL_SCANCODE_J] && !kbPrevState[SDL_SCANCODE_J]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("J");
		}
		else if(kbState[SDL_SCANCODE_K] && !kbPrevState[SDL_SCANCODE_K]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("K");
		}
		else if(kbState[SDL_SCANCODE_L] && !kbPrevState[SDL_SCANCODE_L]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("L");
		}
		else if(kbState[SDL_SCANCODE_M] && !kbPrevState[SDL_SCANCODE_M]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("M");
		}
		else if(kbState[SDL_SCANCODE_N] && !kbPrevState[SDL_SCANCODE_N]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("N");
		}
		else if(kbState[SDL_SCANCODE_O] && !kbPrevState[SDL_SCANCODE_O]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("O");
		}
		else if(kbState[SDL_SCANCODE_P] && !kbPrevState[SDL_SCANCODE_P]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("P");
		}
		else if(kbState[SDL_SCANCODE_Q] && !kbPrevState[SDL_SCANCODE_Q]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("Q");
		}
		else if(kbState[SDL_SCANCODE_R] && !kbPrevState[SDL_SCANCODE_R]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("R");
		}
		else if(kbState[SDL_SCANCODE_S] && !kbPrevState[SDL_SCANCODE_S]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("S");
		}
		else if(kbState[SDL_SCANCODE_T] && !kbPrevState[SDL_SCANCODE_T]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("T");
		}
		else if(kbState[SDL_SCANCODE_U] && !kbPrevState[SDL_SCANCODE_U]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("U");
		}
		else if(kbState[SDL_SCANCODE_V] && !kbPrevState[SDL_SCANCODE_V]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("V");
		}
		else if(kbState[SDL_SCANCODE_W] && !kbPrevState[SDL_SCANCODE_W]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("W");
		}
		else if(kbState[SDL_SCANCODE_X] && !kbPrevState[SDL_SCANCODE_X]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("X");
		}
		else if(kbState[SDL_SCANCODE_Y] && !kbPrevState[SDL_SCANCODE_Y]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("Y");
		}
		else if(kbState[SDL_SCANCODE_Z] && !kbPrevState[SDL_SCANCODE_Z]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("Z");
		}
		else if(kbState[SDL_SCANCODE_0] && !kbPrevState[SDL_SCANCODE_0]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("0");
		}
		else if(kbState[SDL_SCANCODE_1] && !kbPrevState[SDL_SCANCODE_1]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("1");
		}
		else if(kbState[SDL_SCANCODE_2] && !kbPrevState[SDL_SCANCODE_2]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("2");
		}
		else if(kbState[SDL_SCANCODE_3] && !kbPrevState[SDL_SCANCODE_3]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("3");
		}
		else if(kbState[SDL_SCANCODE_4] && !kbPrevState[SDL_SCANCODE_4]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("4");
		}
		else if(kbState[SDL_SCANCODE_5] && !kbPrevState[SDL_SCANCODE_5]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("5");
		}
		else if(kbState[SDL_SCANCODE_6] && !kbPrevState[SDL_SCANCODE_6]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("6");
		}
		else if(kbState[SDL_SCANCODE_7] && !kbPrevState[SDL_SCANCODE_7]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("7");
		}
		else if(kbState[SDL_SCANCODE_8] && !kbPrevState[SDL_SCANCODE_8]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("8");
		}
		else if(kbState[SDL_SCANCODE_9] && !kbPrevState[SDL_SCANCODE_9]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("9");
		}
		else if(kbState[SDL_SCANCODE_BACKSPACE] && !kbPrevState[SDL_SCANCODE_BACKSPACE]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("BACKSPACE");
		}
		else if(kbState[SDL_SCANCODE_RETURN] && !kbPrevState[SDL_SCANCODE_RETURN]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("RETURN");
		}
		else if(kbState[SDL_SCANCODE_LEFT] && !kbPrevState[SDL_SCANCODE_LEFT]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("LEFT");
		}
		else if(kbState[SDL_SCANCODE_RIGHT] && !kbPrevState[SDL_SCANCODE_RIGHT]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("RIGHT");
		}
		else if(kbState[SDL_SCANCODE_UP] && !kbPrevState[SDL_SCANCODE_UP]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("UP");
		}
		else if(kbState[SDL_SCANCODE_DOWN] && !kbPrevState[SDL_SCANCODE_DOWN]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("DOWN");
		}
		else if(kbState[SDL_SCANCODE_PERIOD] && !kbPrevState[SDL_SCANCODE_PERIOD]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey(".");
		}
		else if(kbState[SDL_SCANCODE_SEMICOLON] && !kbPrevState[SDL_SCANCODE_SEMICOLON]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey(";");
		}
		else if(kbState[SDL_SCANCODE_APOSTROPHE] && !kbPrevState[SDL_SCANCODE_APOSTROPHE]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("'");
		}
		else if(kbState[SDL_SCANCODE_COMMA] && !kbPrevState[SDL_SCANCODE_COMMA]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey(",");
		}
		else if(kbState[SDL_SCANCODE_SLASH] && !kbPrevState[SDL_SCANCODE_SLASH]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("/");
		}
		else if(kbState[SDL_SCANCODE_MINUS] && !kbPrevState[SDL_SCANCODE_MINUS]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("-");
		}
		else if(kbState[SDL_SCANCODE_EQUALS] && !kbPrevState[SDL_SCANCODE_EQUALS]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("=");
		}
		else if(kbState[SDL_SCANCODE_KP_PLUS] && !kbPrevState[SDL_SCANCODE_KP_PLUS]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("+");
		}
		else if(kbState[SDL_SCANCODE_SPACE] && !kbPrevState[SDL_SCANCODE_SPACE]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("SPACE");
		}
		else if(kbState[SDL_SCANCODE_RSHIFT] && kbState[SDL_SCANCODE_1]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("!");
		}
		else if(kbState[SDL_SCANCODE_LSHIFT] && kbState[SDL_SCANCODE_1]){
			noKeyPressTime = 0;
			KeyInfo::setCurrentKey("!");
		}
		else{
			noKeyPressTime += deltaTime;
			if(noKeyPressTime > 0.5) // arbitrary amount of time chosen, pick a number that works well
				KeyInfo::setCurrentKey(""); // only set after a certain amount of time has elapsed
		}

		// Game logic goes here.
		if (kbState[SDL_SCANCODE_ESCAPE]) {
			shouldExit = 1;
		}
		

		// ************* Do Updates  **************************************************
		//fmod_sys->update(); // If you don't update the sound will play once

		//gui->update(deltaTime);
		
		//*********** Drawing **********************************************************
		glClearColor(0, 0, 0, 1);  
		glClear(GL_COLOR_BUFFER_BIT); // Be sure to always draw objects after this

		player.draw();

		// Should only be set at beginning after right arrow key pressed, but
		// before textBlock is shown
		//if(showGetReady)
			//glDrawSprite(get_ready, 60, 200, newHighScoreWidth, newHighScoreHeight);

		//*********** Troubleshooting *************************************************
		//printf("Current Key: %s\n", KeyInfo::getCurrentKey().c_str());
		//printf("Previous Key: %s\n", KeyInfo::getPrevKey().c_str());

		
		// Present the most recent frame.
		SDL_GL_SwapWindow(window);

	} //***** END GAME LOOP ********************************************************

	SDL_Quit();

	return 0;
}

/*
* Checks AABB/AABB collisions
* Used to determine if a TextBlock has touched another TextBlock

bool AABBIntersect(AABB box1, AABB box2){
	//box1 to the right
	if(box1.x > box2.x + box2.w){
		return false;
	}

	// box1 top the left
	if(box1.x + box1.w < box2.x){
		return false;
	}

	// box1 below
	if(box1.y > box2.y + box2.h){
		return false;
	}

	// box1 above
	if(box1.y + box1.h < box2.y){
		return false;
	}
	
	return true;
}


// Takes a numeric string and returns its integer representation
int string_to_int(std::string s){
	std::istringstream instr(s);
	int n;
	instr >> n;
	return n;
}

// convert an integer to a string. return the string
std::string int_to_string(int n){
	ostringstream oss;
	oss << n;
	return oss.str();
}
*/