#pragma once
#include "Includes.h"
#include "GameObject.h"
#include "Mesh.h"


class MeshedGameObject : public GameObject {
protected:
	Mesh* _mesh;
public:
	MeshedGameObject();

	void pollEvents(float dt);

	virtual void genMyModelMatrix(glm::vec3 pos, glm::vec3 rot, glm::vec3 scale);
	virtual void setNewVertexBufferData(std::vector<glm::vec3> locs);
	virtual void attachShaders(std::string vFilename, std::string fFileName);
};

