#include "Scene.h"

Scene::Scene() {
	_camera = new Camera(0.0005f, 90.0f, 0.1f, 1000.0f);
	if (_camera == nullptr) {
		std::cout << "ERROR CAMERA THINGY\n";
	}
}

void Scene::scenePollEvents(float dt) {
	_camera->pollEvents(dt);

	for (unsigned short i = 0; i < _gameObjects.size(); i++) {
		_gameObjects[i].pollEvents(dt);
	}
}

GameObject* Scene::getSceneMember(unsigned short num) {
	return &_gameObjects.data()[num];
}

std::vector<GameObject>* Scene::getObjList() {
	return &_gameObjects;
}

unsigned short Scene::newElement() {
	GameObject newObj;
	_gameObjects.push_back(newObj);
	return unsigned short(_gameObjects.size() - 1); // TEMPORARY SOLUTION THIS IS A VERY BAD PRACTICE!!!!!!!
}
unsigned short Scene::newElement(GameObject obj) {
	_gameObjects.push_back(newObj);
	return unsigned short(_gameObjects.size() - 1); // TEMPORARY SOLUTION THIS IS A VERY BAD PRACTICE!!!!!!!
}