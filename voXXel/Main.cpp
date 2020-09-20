#include "Includes.h"
#include "Tests.h"
#include "Engine.h"
class VoXXel;

int main() {
	//runTests();


	Engine* engine = new Engine(800, 600, "voXXel engine [TESTING]", false);
	if (!VoXXel::setMainEngine(engine)) return 1;


	std::vector<glm::vec3> g_vertex_buffer_data = {
		glm::vec3(-1.0f, -1.0f, 0.0f),
		glm::vec3(1.0f, -1.0f, 0.0f),
		glm::vec3(0.0f,  1.0f, 0.0f),
	};

	unsigned short objCode = engine->getScene()->newElement();
	GameObject* obj = engine->getScene()->getSceneMember(objCode);
	obj->setNewBufferData(g_vertex_buffer_data);
	obj->attachShaders("Data/Shaders/vertex.glsl", "Data/Shaders/fragment.glsl");



	while (!glfwGetKey(engine->getWindow(), GLFW_KEY_ESCAPE))	{
		engine->update();
	}

	engine->shutdown();

	return 0;
}