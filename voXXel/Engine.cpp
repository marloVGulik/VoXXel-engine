#include "Engine.h"


Engine::Engine(unsigned int w, unsigned int h, std::string title, bool fullscreen) {
	_console = new Console(0, "logs/log.html");


	// Initiate variables
	_fullscreen = fullscreen;
	_windowWidth = w;
	_windowHeight = h;


	// time vars
	_startTime = (float)glfwGetTime();
	_oldTime = (float) glfwGetTime();
	_currentTime = (float) glfwGetTime();
	_deltaTime = 1;

	// Initiate window
	_console->engine("Setting up GLFW and window.");
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	if (!glfwInit()) {
		_console->error("GLFW NOT INITIATED!");
	}


	// Set up screen
	_monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* mode = glfwGetVideoMode(_monitor);

	if (fullscreen) {
		glfwWindowHint(GLFW_RED_BITS, mode->redBits);
		glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
		glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
		glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

		_window = glfwCreateWindow(mode->width, mode->height, _title.c_str(), _monitor, NULL);
	} else {
		_window = glfwCreateWindow(_windowWidth, _windowHeight, _title.c_str(), NULL, NULL);
	}


	glfwMakeContextCurrent(_window);
	glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		_console->error("GLEW NOT INITIATED!");
	}
	glClearColor(0.16015625f, 0.16015625f, 0.16015625f, 1.0f);

	_console->engine("voXXel set up succesfully!");
}

void Engine::update() {
	// Delta calculation! IMPORTANT
	_deltaTime = float(_currentTime - _oldTime);
	_oldTime = _currentTime;
	_currentTime = (float) glfwGetTime();
	// Frame and FPS counting
	_frame++;
	_FPSEstimation += unsigned int(1 / _deltaTime);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor(0.16015625f, 0.16015625f, 0.16015625f, 1.0f);

	glfwSwapBuffers(_window);
	glfwPollEvents();

}

// Getters
float Engine::getDeltaTime() {
	return _deltaTime;
}
GLFWwindow* Engine::getWindow() {
	return _window;
}

void Engine::shutdown() {
	_console->engine("voXXel engine is shutting down! Overall FPS is " + std::to_string(_FPSEstimation / _frame) + " and total frame amount is " + std::to_string(_frame));
	
	if (_window != nullptr) {
		glfwDestroyWindow(_window);
	}
}