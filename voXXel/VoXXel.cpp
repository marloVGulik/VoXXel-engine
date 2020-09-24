#include "VoXXel.h"

bool VoXXel::isMainEngineSet = false;
Engine* VoXXel::mainEngine = nullptr;

bool VoXXel::setMainEngine(Engine* engine) {
	VoXXel::isMainEngineSet = true;
	if (isMainEngineSet) {
		VoXXel::mainEngine = engine;
		glfwSetWindowSizeCallback(engine->getWindow(), VoXXel::windowSizeChange);
		return true;
	}
	return false;
}

Engine* VoXXel::getMainEngine() {
	if(VoXXel::isMainEngineSet) return VoXXel::mainEngine;
	return nullptr;
}

void VoXXel::windowSizeChange(GLFWwindow* window, int width, int height) {
	if (VoXXel::isMainEngineSet) {
		VoXXel::getMainEngine()->getConsole()->log("Window was resized!");
		glViewport(0, 0, width, height);
		mainEngine->update();
	}
}
