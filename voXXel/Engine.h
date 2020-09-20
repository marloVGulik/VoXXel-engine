#pragma once
#include "Includes.h"
#include "Scene.h"

class Scene;

class Engine {
private: // Variables


	// Engine variables
	unsigned int _frame = 0;
	unsigned int _FPSEstimation = 0;

	// Engine timing variables
	float _startTime;
	float _deltaTime;
	float _currentTime;
	float _oldTime;

	// Window variables
	std::string _title;
	bool _fullscreen;
	unsigned int _windowWidth;
	unsigned int _windowHeight;

	// GLFW variables
	GLFWwindow* _window;
	GLFWmonitor* _monitor;

	// OpenGL variables
	GLuint _matrixID;
	GLuint _programID;

	// Other variables
	Console* _console;
	Scene* _scene;

public:
	Engine(unsigned int w, unsigned int h, std::string title, bool fullscreen);
	~Engine();

	void update();

	// Getters
	float getDeltaTime();
	GLFWwindow* getWindow();
	glm::vec2 getWindowDimensions();
	Console* getConsole();
	Scene* getScene();

	void shutdown();
};

