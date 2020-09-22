#include "Mesh.h"

void Mesh::newMesh(std::string fName) {

}

void Mesh::genMyModelMatrix(glm::vec3 pos, glm::vec3 rot, glm::vec3 scale) {
	glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), pos);
	glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), 360.0f, rot);
	glm::mat4 scalingMatrix = glm::scale(glm::mat4(1.0f), scale);

	_myModel = translationMatrix * rotationMatrix * scalingMatrix;
}
void Mesh::setNewVertexBufferData(std::vector<glm::vec3> locs) { // Set new vertex buffer data
	glGenBuffers(1, &_myVertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, _myVertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(locs.data()[0]) * locs.size(), locs.data(), GL_STATIC_DRAW);
}
void Mesh::attachShaders(std::string vFilename, std::string fFileName) { // Attach shader to object
	//printf("Setting up shaders for object");
	_myShaderProgramID = LoadShaders(vFilename.c_str(), fFileName.c_str());
}

void Mesh::pollEvents(float dt, glm::vec3 pos, glm::vec3 rot, glm::vec3 scale) {
	glUseProgram(_myShaderProgramID); // Use shader

	genMyModelMatrix(pos, rot, scale); // Calc M
	glm::mat4 MVP = VoXXel::getMainEngine()->getScene()->getPV() * _myModel; // Calc MVP
	glUniformMatrix4fv(_MVP, 1, GL_FALSE, &MVP[0][0]); // Set MVP in shader

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, _myTexture);
	glUniform1i(_myTextureID, 0);

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
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, _myUVBuffer);
	glVertexAttribPointer(
		1,
		2,
		GL_FLOAT,
		GL_TRUE,
		0,
		(void*)0
	);
	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, _myNormalBuffer);
	glVertexAttribPointer(
		2,
		3,
		GL_FLOAT,
		GL_TRUE,
		0,
		(void*)0
	);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _myVertexIndexBuffer);
	glDrawElements(
		GL_TRIANGLES,
		_vertSize,
		GL_UNSIGNED_INT,
		(void*)0
	);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
}

Mesh::Mesh() {
	_myModel = glm::mat4(1.0f);

	glGenVertexArrays(1, &_myVertexArrayID);
	glBindVertexArray(_myVertexArrayID);
}
Mesh::Mesh(std::string fName) {
	// Load data from drive
	std::vector<glm::vec3> objVert;
	std::vector<glm::vec2> objUV;
	std::vector<glm::vec3> objNorm;
	std::vector<unsigned int> objVBO;

	_vertSize = loadOBJfile("Data/Meshes/" + fName + "/" + fName + ".obj", objVert, objUV, objNorm, objVBO);
	if (_vertSize == 0) {
		VoXXel::getMainEngine()->getConsole()->error("OBJECT NOT FOUND: " + fName);
	}
	
	_myTexture = loadBMP("Data/Meshes/" + fName + "/" + fName + ".bmp");
	// Give texture to GLSL

	if (glewInit() != GLEW_OK) {
		VoXXel::getMainEngine()->getConsole()->error("There appear to be GLEW issues! (Occured during object loading)");
	}

	// Setting buffers
	glGenBuffers(1, &_myVertexBuffer);	// Vertex buffer
	glBindBuffer(GL_ARRAY_BUFFER, _myVertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(objVert.data()[0]) * objVert.size(), objVert.data(), GL_STATIC_DRAW);

	glGenBuffers(1, &_myUVBuffer);		// UV buffer
	glBindBuffer(GL_ARRAY_BUFFER, _myUVBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(objUV.data()[0]) * objUV.size(), objUV.data(), GL_STATIC_DRAW);

	glGenBuffers(1, &_myNormalBuffer);	// Normal buffer
	glBindBuffer(GL_ARRAY_BUFFER, _myNormalBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(objNorm.data()[0]) * objNorm.size(), objNorm.data(), GL_STATIC_DRAW);

	glGenBuffers(1, &_myVertexIndexBuffer);	// Index buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _myVertexIndexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(objVBO.data()[0]) * objVBO.size(), objVBO.data(), GL_STATIC_DRAW);

	// Attaching shaders
	_myShaderProgramID = LoadShaders(std::string("Data/Meshes/" + fName + "/" + fName + ".vShader").c_str(), std::string("Data/Meshes/" + fName + "/" + fName + ".fShader").c_str());

	// Getting uniform locations from shaders
	_MVP = glGetUniformLocation(_myShaderProgramID, "MVP");
}

Mesh::~Mesh() {
	glDeleteBuffers(1, &_myVertexBuffer);
	glDeleteBuffers(1, &_myUVBuffer);
	glDeleteBuffers(1, &_myNormalBuffer);
	glDeleteTextures(1, &_myVertexBuffer);
}