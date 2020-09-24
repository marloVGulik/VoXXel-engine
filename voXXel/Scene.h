#pragma once
#include "Includes.h"
#include "GameObjects.h"

class Camera;

class Scene {
private:
	std::vector<GameObject*> _gameObjects;
	Camera* _camera;

public:
	Scene();
	~Scene();

	void scenePollEvents(float dt);

	GameObject& getSceneMember(unsigned short num);
	std::vector<GameObject*>& getObjList();
	glm::mat4 getPV();
	
	unsigned short newElement();
	void newElement(GameObject* obj);
};

