#include "Mesh.h"

Mesh::Mesh() {
	_model = glm::mat4(1.0f);

	glGenVertexArrays(1, &_myVertexArrayID);
	glBindVertexArray(_myVertexArrayID);
}

Mesh::~Mesh() {

}

void Mesh::genMyModelMatrix(glm::vec3 pos, glm::vec3 rot, glm::vec3 scale) {
	glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), pos);
	glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), 360.0f, rot);
	glm::mat4 scalingMatrix = glm::scale(glm::mat4(1.0f), scale);

	_model = translationMatrix * rotationMatrix * scalingMatrix;
}
void Mesh::setNewVertexBufferData(std::vector<glm::vec3> locs) { // Set new vertex buffer data
	glGenBuffers(1, &_myVertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, _myVertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(locs.data()[0]) * locs.size(), locs.data(), GL_STATIC_DRAW);
}
void Mesh::attachShaders(std::string vFilename, std::string fFileName) { // Attach shader to object
	//printf("Setting up shaders for object");
	_shaderProgramID = LoadShaders(vFilename.c_str(), fFileName.c_str());
}

void Mesh::pollEvents(float dt, glm::vec3 pos, glm::vec3 rot, glm::vec3 scale) {
	genMyModelMatrix(pos, rot, scale);

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
