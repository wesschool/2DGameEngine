#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm\glm.hpp>

using namespace glm;

// Represents the current state of the game
enum GameState {
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN,
	EDITOR_ACTIVE
};

// class that breaks the game/engine up into 3 main parts
class Game
{
public:
	Game(GLuint width, GLuint height);
	~Game();
	
	// game state
	GameState              State;
	GLboolean              Keys[1024];
	GLboolean			   Mouse[10];
	dvec2			       MousePosition;
	GLuint                 Width, Height;
	
	// load levels and setup managers
	void Init();
	
	// main game loop
	void ProcessInput(GLfloat dt);
	void Update(GLfloat dt, GLFWwindow* window);
	void Render();
};