#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Game.h"
#include "ResourceManager.h"

// GLFW function declerations
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

// The Width of the screen
const GLuint SCREEN_WIDTH = 1920;
// The height of the screen
const GLuint SCREEN_HEIGHT = 1080;

Game GameEngine(SCREEN_WIDTH, SCREEN_HEIGHT);

int main(int argc, char *argv[])
{

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Game Engine Version 1", glfwGetPrimaryMonitor(), nullptr);
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	glewInit();
	glGetError(); // Call it once to catch glewInit() bug, all other errors are now from our application.

	glfwSetKeyCallback(window, key_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);

	//Initialize the game
	GameEngine.Initialize();

	// OpenGL configuration
	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	// Start Game within Menu State
	GameEngine.State = GAME_ACTIVE;

	while (!glfwWindowShouldClose(window))
	{
		//will set up as a call back later (which is the currect way to implement it)
		glfwGetCursorPos(window, &GameEngine.MousePosition.x, &GameEngine.MousePosition.y);

		// Calculate delta time
		GLfloat currentFrame = glfwGetTime();
		GameEngine.DeltaTime = currentFrame - GameEngine.LastFrame;
		GameEngine.LastFrame = currentFrame;
		glfwPollEvents();

		// Manage user input
		GameEngine.ProcessInput();

		// Update Game state
		GameEngine.Update();

		// Render
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		GameEngine.Render();

		glfwSwapBuffers(window);
	}

	// Delete all resources as loaded using the resource manager
	ResourceManager::Clear();

	glfwTerminate();
	return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	// When a user presses the escape key, we set the WindowShouldClose property to true, closing the application
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
			GameEngine.Keys[key] = GL_TRUE;
		else if (action == GLFW_RELEASE)
			GameEngine.Keys[key] = GL_FALSE;
	}
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (button >= 0 || button <= 9)
		if (action == GLFW_PRESS)
			GameEngine.Mouse[button] = GL_TRUE;
		else if (action == GLFW_RELEASE)
			GameEngine.Mouse[button] = GL_FALSE;
}
