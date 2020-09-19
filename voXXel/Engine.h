#pragma once
#include "Includes.h"
#include "Console.h"

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

	// Rendering variables
	glm::mat4 _projection;

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

public:
	Engine(unsigned int w, unsigned int h, std::string title, bool fullscreen);
	~Engine();

	void update();

	float getDeltaTime();
	GLFWwindow* getWindow();

	void shutdown();
};

