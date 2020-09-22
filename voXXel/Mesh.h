#pragma once
#include "Includes.h"
#include "OBJloader.h"
#include "loadBMP.h"
#include "Camera.h"

class Mesh {
private:
	glm::mat4 _myModel;

	GLuint _MVP;

	GLuint _myVertexArrayID;
	GLuint _myVertexBuffer;
	unsigned int _vertSize;

	GLuint _myVertexIndexBuffer;

	GLuint _myUVBuffer;
	GLuint _myTextureID;
	GLuint _myTexture;

	GLuint _myNormalBuffer;
	GLuint _myNormalBufferID;

	GLuint _myShaderProgramID;

public:
	// Model stuff
	void newMesh(std::string fName);

	void genMyModelMatrix(glm::vec3 pos, glm::vec3 rot, glm::vec3 scale);
	void setNewVertexBufferData(std::vector<glm::vec3> locs);
	void attachShaders(std::string vFilename, std::string fFileName);


	void pollEvents(float dt, glm::vec3 pos, glm::vec3 rot, glm::vec3 scale);

	// Constructors
	Mesh();
	Mesh(std::string fName);

	~Mesh();
};

