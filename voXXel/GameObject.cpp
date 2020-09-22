#include "GameObject.h"

GameObject::GameObject() {
	_myPosition = glm::vec3(0.0f);
	_myRotation = glm::vec3(0.0f);
	_myScale = glm::vec3(1.0f);
}

GameObject::GameObject(glm::vec3 pos, glm::vec3 rot, glm::vec3 scale) {
	_myPosition = pos;
	_myRotation = rot;
	_myScale = scale;
}

void GameObject::behaviour(float dt) {

}

void GameObject::pollEvents(float dt) {
	if (!shown) {
		std::cout << "Oh\n";
		return;
	}

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

glm::vec3 GameObject::getMyPosition() {
	return _myPosition;
}

glm::vec3 GameObject::getMyRotation() {
	return _myRotation;
}

glm::vec3 GameObject::getMyScale() {
	return _myScale;
}

void GameObject::genMyModelMatrix(glm::vec3 pos, glm::vec3 rot, glm::vec3 scale)
{
}

void GameObject::setNewVertexBufferData(std::vector<glm::vec3> locs)
{
}

void GameObject::attachShaders(std::string vFilename, std::string fFileName)
{
}
