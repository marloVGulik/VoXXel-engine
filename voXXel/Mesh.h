#pragma once
#include "Includes.h"

class Mesh {
private:

	glm::mat4 _model;
	GLuint _myVertexArrayID;
	GLuint _myVertexBuffer;
	GLuint _shaderProgramID;

public:
	Mesh();
	~Mesh();

	// Model stuff
	void genMyModelMatrix(glm::vec3 pos, glm::vec3 rot, glm::vec3 scale);
	void setNewVertexBufferData(std::vector<glm::vec3> locs);
	void attachShaders(std::string vFilename, std::string fFileName);


	void pollEvents(float dt, glm::vec3 pos, glm::vec3 rot, glm::vec3 scale);
};

