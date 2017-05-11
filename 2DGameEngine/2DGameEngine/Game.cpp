#include "Game.h"
#include "ResourceManager.h"
#include "SpriteRenderer.h"
#include "ObjectEditor.h"
#include "WorldManager.h"
#include "Drawer.h"

SpriteRenderer* Renderer;
ObjectEditor* Editor;
WorldManager *World;
Drawer* drawer;

float rotation;
Game::Game(GLuint width, GLuint height)
	: State(GAME_ACTIVE), Keys(), Width(width), Height(height)
{
	
}

Game::~Game()
{

}

void Game::Initialize()
{
	//Load shaders
	ResourceManager::LoadShader("Shaders/Sprite.vert", "Shaders/Sprite.frag", nullptr, "sprite");
	//Configure shaders
	glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(this->Width),
		static_cast<GLfloat>(this->Height), 0.0f, -1.0f, 1.0f);
	ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
	ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);

	World = new WorldManager();
	Renderer = new SpriteRenderer(ResourceManager::GetShader("sprite"));
	drawer = new Drawer();


	//Load textures
	ResourceManager::LoadTexture("Textures/container.jpg", GL_TRUE, "container");
	ResourceManager::LoadTexture("Textures/background.jpg", GL_TRUE, "background");

	World->Add(new Rect(glm::vec2(100, 100), glm::vec2(50, 50), ResourceManager::GetTexture("container")));
	World->Add(new Rect(glm::vec2(500, 100), glm::vec2(50, 50), ResourceManager::GetTexture("container")));
	World->Add(new Rect(glm::vec2(200, 100), glm::vec2(50, 50), ResourceManager::GetTexture("container"), glm::vec3(1, 1, 1), glm::vec2(.3, 0)));
	World->Add(new Rect(glm::vec2(300, 100), glm::vec2(50, 50), ResourceManager::GetTexture("container"), glm::vec3(1, 1, 1), glm::vec2(-.1, 0)));
}

void Game::Update(GLfloat dt, GLFWwindow* window)
{
	
	//currently active
	if(State == GAME_ACTIVE)
		World->UpdateWorld();
	
	//no way to activate in game (WIP)
	//if (State == EDITOR_ACTIVE)
	
	
}


void Game::ProcessInput(GLfloat dt)
{

}

void Game::Render()
{
	// Draw background
	Renderer->DrawSprite(ResourceManager::GetTexture("background"),
		glm::vec2(0, 0), glm::vec2(this->Width, this->Height), 0.0f, glm::vec3(glm::sin(glfwGetTime()), 1, 1));

	World->Accept(drawer);
}