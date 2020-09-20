#pragma once
#include "Includes.h"

class GameObject {
protected:
	bool shown = false;

	glm::mat4 _model;
	glm::vec3 _myPosition;
	glm::vec3 _myRotation;
	glm::vec3 _myScale;

	GLuint _myVertexArrayID;
	GLuint _myVertexBuffer;
	GLuint _shaderProgramID;
public:
	GameObject();
	GameObject(glm::vec3 pos, glm::vec3 rot, glm::vec3 scale);
	//~GameObject();

	void behaviour(float dt);
	void pollEvents(float dt);
	void genMyModelMatrix();

	// Setters
	void setMyPosition(glm::vec3 pos);
	void setMyRotation(glm::vec3 rot);
	void setMyScale(glm::vec3 scale);

	void setNewBufferData(std::vector<glm::vec3> locs);
	void attachShaders(std::string vFilename, std::string fFileName);

	// Getters
	glm::vec3 getMyPosition();
	glm::vec3 getMyRotation();
	glm::vec3 getMyScale();
};

