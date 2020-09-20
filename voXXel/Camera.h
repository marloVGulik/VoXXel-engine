#pragma once
#include "Includes.h"
#include "GameObject.h"
#include "Engine.h"
#include "VoXXel.h"

class Camera: public GameObject {
protected:
	// Camera stuff
	float _speed;
	float _sensitivity;
	float _FoV;
	float _clipDistance;
	float _drawDistance;

	float _hAngle;
	float _vAngle;


	// View
	glm::mat4 _view;
	glm::mat4 _projection;

public:
	Camera();
	Camera(float sensitivity, float FoV, float clipDistance, float drawDistance);

	// Getters
	glm::mat4 getView();

	void pollEvents(float dt);
};

