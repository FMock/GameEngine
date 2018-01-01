#define SDL_MAIN_HANDLED
#include<SDL.h>
#include<GL/glew.h>
#include<stdio.h>
#include<string>
#include<iostream>
#include<assert.h>
#include"DrawUtils.h"
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


		// Take action if any keys are pressed
		if (kbState[SDL_SCANCODE_RIGHT]) {
			printf("Right arrow pressed\n");
		}
		else if (kbState[SDL_SCANCODE_LEFT]) {
			printf("Left arrow pressed\n");
		}
		else if (kbState[SDL_SCANCODE_UP]) {
			printf("Up arrow pressed\n");
		}
		else if (kbState[SDL_SCANCODE_DOWN]) {
			printf("Down arrow pressed\n");
		}else if(kbState[SDL_SCANCODE_F1]){
			//printf("F1 pressed\n");
		}
		else if(kbState[SDL_SCANCODE_A] && !kbPrevState[SDL_SCANCODE_A]){
			printf("A key pressed\n");
		}
		else if(kbState[SDL_SCANCODE_B] && !kbPrevState[SDL_SCANCODE_B]){
			printf("B key pressed\n");
		}
		else if(kbState[SDL_SCANCODE_C] && !kbPrevState[SDL_SCANCODE_C]){
			printf("C key pressed\n");
		}
		else{
			//textBlock->stop();
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

		// Should only be set at beginning after right arrow key pressed, but
		// before textBlock is shown
		//if(showGetReady)
			//glDrawSprite(get_ready, 60, 200, newHighScoreWidth, newHighScoreHeight);

		//*********** Troubleshooting *************************************************
		//printf(stats.to_string().c_str());
		//printf(gameData->to_string().c_str());
		
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