#include "Includes.h"
#include "Tests.h"
#include "Engine.h"

int main() {
	//runTests();


	Engine* engine = new Engine(800, 600, "voXXel engine [TESTING]", false);


	while (!glfwGetKey(engine->getWindow(), GLFW_KEY_ESCAPE))	{
		engine->update();
	}

	engine->shutdown();

	return 0;
}