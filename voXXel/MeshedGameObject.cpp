#include "MeshedGameObject.h"

MeshedGameObject::MeshedGameObject() {
	_myPosition = glm::vec3(0.0f);
	_myRotation = glm::vec3(0.0f);
	_myScale = glm::vec3(1.0f);
}

MeshedGameObject::MeshedGameObject(std::string objFile) {
	_myPosition = glm::vec3(0.0f);
	_myRotation = glm::vec3(0.0f);
	_myScale = glm::vec3(1.0f);

	_meshes.push_back(new Mesh(objFile));
}

void MeshedGameObject::behaviour(float dt) {
	_myRotation += glm::vec3(0.0f, 10.0f * dt, 0.0f);
}
void MeshedGameObject::pollEvents(float dt) {
	for (unsigned short i = 0; i < _meshes.size(); i++) {
		_meshes[i]->pollEvents(dt, _myPosition, _myRotation, _myScale);
	}
}

void MeshedGameObject::genMyModelMatrix(glm::vec3 pos, glm::vec3 rot, glm::vec3 scale) {
	for (unsigned short i = 0; i < _meshes.size(); i++) {
		_meshes[i]->genMyModelMatrix(pos, rot, scale);
	}
}

void MeshedGameObject::newMesh(std::string loc) {
	_meshes.push_back(new Mesh(loc));
}
