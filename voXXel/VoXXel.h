#pragma once
#include "Includes.h"
#include "Engine.h"

class Engine;


class VoXXel {
public:
	// Engine stuff
	static bool isMainEngineSet;
	static Engine* mainEngine;

	// Setters
	static bool setMainEngine(Engine* engine);

	// Getters
	static Engine* getMainEngine();

	// Callbacks
	static void windowSizeChange(GLFWwindow* window, int width, int height);
};

