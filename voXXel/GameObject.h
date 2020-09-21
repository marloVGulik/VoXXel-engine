#pragma once
#include "Includes.h"

class GameObject {
protected:
	bool shown = false;

	glm::vec3 _myPosition;
	glm::vec3 _myRotation;
	glm::vec3 _myScale;


public:
	GameObject();
	GameObject(glm::vec3 pos, glm::vec3 rot, glm::vec3 scale);
	//~GameObject();

	void behaviour(float dt);
	void pollEvents(float dt);

	// Setters
	void setMyPosition(glm::vec3 pos);
	void setMyRotation(glm::vec3 rot);
	void setMyScale(glm::vec3 scale);


	// Getters
	glm::vec3 getMyPosition();
	glm::vec3 getMyRotation();
	glm::vec3 getMyScale();
};

