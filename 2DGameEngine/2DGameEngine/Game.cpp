#include "Game.h"
#include "ResourceManager.h"
#include "SpriteRenderer.h"
#include "ObjectManager.h"
#include "Rect.h"
#include "ObjectEditor.h"

SpriteRenderer* Renderer;
ObjectManager* Manager;
ObjectEditor* Editor;

float rotation;
Game::Game(GLuint width, GLuint height)
	: State(GAME_ACTIVE), Keys(), Width(width), Height(height)
{

}

Game::~Game()
{

}

void Game::Init()
{
	//Load shaders
	ResourceManager::LoadShader("Shaders/Sprite.vert", "Shaders/Sprite.frag", nullptr, "sprite");
	//Configure shaders
	glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(this->Width),
		static_cast<GLfloat>(this->Height), 0.0f, -1.0f, 1.0f);
	ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
	ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
	
	Manager = new ObjectManager();
	Renderer = new SpriteRenderer(ResourceManager::GetShader("sprite"));
	Editor = new ObjectEditor(Manager, this->Keys, this->Mouse);

	//Load textures
	ResourceManager::LoadTexture("Textures/container.jpg", GL_TRUE, "container");
	ResourceManager::LoadTexture("Textures/background.jpg", GL_TRUE, "background");
	//optional parameter
	Manager->add(new Rect(glm::vec2(200, 200), glm::vec2(50,50), ResourceManager::GetTexture("container"), glm::vec3(1, 1, 1), glm::vec2(0, 0)));
	Manager->add(new Rect(glm::vec2(100, 200), glm::vec2(100, 100), ResourceManager::GetTexture("container"), glm::vec3(1, 1, 1), glm::vec2(0, 0)));
	Manager->add(new Rect(glm::vec2(400, 200), glm::vec2(200, 200), ResourceManager::GetTexture("container"), glm::vec3(1, 1, 1), glm::vec2(0, 0)));
	Manager->add(new Rect(glm::vec2(450, 500), glm::vec2(100, 300), ResourceManager::GetTexture("container"), glm::vec3(1, 1, 1), glm::vec2(0, 0)));
}

void Game::Update(GLfloat dt, GLFWwindow* window)
{
	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);
	
	if (this->Keys[GLFW_KEY_1])
		Editor->Enabled = !Editor->Enabled;

	Editor->Update(glm::vec2(xpos, ypos));
	
}


void Game::ProcessInput(GLfloat dt)
{

}

void Game::Render()
{
	// Draw background
	Renderer->DrawSprite(ResourceManager::GetTexture("background"),
		glm::vec2(0, 0), glm::vec2(this->Width, this->Height), 0.0f, glm::vec3(glm::sin(glfwGetTime()), 1, 1));

	Manager->draw(Renderer);
}