#include "MeshedGameObject.h"

MeshedGameObject::MeshedGameObject() {
	_myPosition = glm::vec3(0.0f);
	_myRotation = glm::vec3(0.0f);
	_myScale = glm::vec3(1.0f);

	_mesh = new Mesh();
}

MeshedGameObject::MeshedGameObject(std::string objFile) {
	_myPosition = glm::vec3(0.0f);
	_myRotation = glm::vec3(0.0f);
	_myScale = glm::vec3(1.0f);

	_mesh = new Mesh();
}

void MeshedGameObject::pollEvents(float dt) {
	_mesh->pollEvents(dt, _myPosition, _myRotation, _myScale);
}

void MeshedGameObject::genMyModelMatrix(glm::vec3 pos, glm::vec3 rot, glm::vec3 scale) {
	_mesh->genMyModelMatrix(pos, rot, scale);
}

void MeshedGameObject::setNewVertexBufferData(std::vector<glm::vec3> locs) {
	_mesh->setNewVertexBufferData(locs);
}

void MeshedGameObject::attachShaders(std::string vFilename, std::string fFileName) {
	_mesh->attachShaders(vFilename, fFileName);
}
