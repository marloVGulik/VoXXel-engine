#include "GameObject.h"

GameObject::GameObject() {
	_myPosition = glm::vec3(0.0f);
	_myRotation = glm::vec3(0.0f);
	_myScale = glm::vec3(1.0f);
	_model = glm::mat4(1.0f);

	glGenVertexArrays(1, &_myVertexArrayID);
	glBindVertexArray(_myVertexArrayID);
}

GameObject::GameObject(glm::vec3 pos, glm::vec3 rot, glm::vec3 scale) {
	_myPosition = pos;
	_myRotation = rot;
	_myScale = scale;
	_model = glm::mat4(1.0f);

	glGenVertexArrays(1, &_myVertexArrayID);
	glBindVertexArray(_myVertexArrayID);
}

void GameObject::behaviour(float dt) {

}

void GameObject::pollEvents(float dt) {
	if (!shown) {
		std::cout << "Oh\n";
		return;
	}

	genMyModelMatrix();
	
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, _myVertexBuffer);
	glVertexAttribPointer(
		0,
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
	);
	glUseProgram(_shaderProgramID);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);
}

void GameObject::genMyModelMatrix() {
	glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), _myPosition);
	glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), 360.0f, _myRotation);
	glm::mat4 scalingMatrix = glm::scale(glm::mat4(1.0f), _myScale);

	_model = translationMatrix * rotationMatrix * scalingMatrix;
}

void GameObject::setMyPosition(glm::vec3 pos) {
	_myPosition = pos;
}

void GameObject::setMyRotation(glm::vec3 rot) {
	_myRotation = rot;
}

void GameObject::setMyScale(glm::vec3 scale) {
	_myScale = scale;
}

void GameObject::setNewBufferData(std::vector<glm::vec3> locs) {
	glGenBuffers(1, &_myVertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, _myVertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(locs.data()[0]) * locs.size(), locs.data(), GL_STATIC_DRAW);

	shown = true;
}

void GameObject::attachShaders(std::string vFilename, std::string fFileName) {
	_shaderProgramID = LoadShaders(vFilename.c_str(), fFileName.c_str());
}

glm::vec3 GameObject::getMyPosition() {
	return _myPosition;
}

glm::vec3 GameObject::getMyRotation() {
	return _myRotation;
}

glm::vec3 GameObject::getMyScale() {
	return _myScale;
}
