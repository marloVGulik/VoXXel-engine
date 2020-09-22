#include "Includes.h"
#include "Tests.h"
#include "Engine.h"
#include "MeshedGameObject.h"

class VoXXel;
class MeshedGameObject;

int main() {
	//runTests();


	Engine* engine = new Engine(800, 600, "voXXel engine [TESTING]", false);
	if (!VoXXel::setMainEngine(engine)) return 1;


	//std::vector<glm::vec3> g_vertex_buffer_data = {
	//	glm::vec3(-1.0f, -1.0f, 0.0f),
	//	glm::vec3(1.0f, -1.0f, 0.0f),
	//	glm::vec3(0.0f,  1.0f, 0.0f),
	//};

	GameObject* obj = new MeshedGameObject("testMesh");
	engine->getScene()->newElement(obj);

	//std::vector<glm::vec3> g_vertex_buffer_data2 = {
	//	glm::vec3(1.0f, 1.0f, 0.0f),
	//	glm::vec3(-1.0f, 1.0f, 0.0f),
	//	glm::vec3(0.0f,  -1.0f, 0.0f),
	//};
	//unsigned short obj2 = engine->getScene()->newElement();
	//Scene* scene = engine->getScene();
	//scene->getObjList()->data()[obj2] = new MeshedGameObject();
	//scene->getObjList()->data()[obj2]->setNewVertexBufferData(g_vertex_buffer_data2);
	//scene->getObjList()->data()[obj2]->attachShaders("Data/Shaders/vertex.glsl", "Data/Shaders/fragment.glsl");

	//engine->getScene()->getObjList()->data()[objCode] = MeshedGameObject();
	//engine->getScene()->getObjList()->data()[objCode]->setNewVertexBufferData(g_vertex_buffer_data);
	//engine->getScene()->getObjList()->data()[objCode]->attachShaders("Data/Shaders/vertex.glsl", "Data/Shaders/fragment.glsl");



	while (!glfwGetKey(engine->getWindow(), GLFW_KEY_ESCAPE))	{
		engine->update();
	}

	engine->shutdown();

	return 0;
}