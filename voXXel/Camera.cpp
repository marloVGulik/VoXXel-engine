#include "Camera.h"

Camera::Camera() {
	_sensitivity = 0.0005f;
	_FoV = 90.0f;
	_clipDistance = 0.1f;
	_drawDistance = 1000.0f;

	//pollEvents(0); // DON'T COMMIT FUNCTION IN CONSTRUCTOR :(
}
Camera::Camera(float sensitivity, float FoV, float clipDistance, float drawDistance) {
	_sensitivity = sensitivity;
	_FoV = FoV;
	_clipDistance = clipDistance;
	_drawDistance = drawDistance;

	//pollEvents(0);
}

glm::mat4 Camera::getView() {
	return _view;
}

glm::mat4 Camera::getProjection() {
	return _projection;
}

void Camera::pollEvents(float dt) {
	Engine* engine = VoXXel::getMainEngine(); // Get engine
	GLFWwindow* window = engine->getWindow(); // Get window

	// Get window dimensions
	glm::vec2 wSize = engine->getWindowDimensions();

	// Get new angles from mouse position
	double mouseX, mouseY;
	glfwGetCursorPos(window, &mouseX, &mouseY);
	_hAngle += float(_sensitivity * (wSize.x / 2 - mouseX));
	_vAngle += float(_sensitivity * (wSize.y / 2 - mouseY));

	_myRotation = glm::vec3( // Set new angle rotation
		cos(_vAngle) * sin(_hAngle),
		sin(_vAngle),
		cos(_vAngle) * cos(_hAngle)
	);
	
	// Right and up directions
	glm::vec3 right = glm::vec3(
		sin(_hAngle - 3.14f / 2.0f),
		0,
		cos(_hAngle - 3.14f / 2.0f)
	);
	glm::vec3 up = glm::cross(right, _myRotation);


	// Setting view and projection
	_view = glm::lookAt(
		_myPosition,
		_myPosition + _myRotation,
		up
	);
	_projection = glm::perspective(glm::radians(_FoV), wSize.x / wSize.y, _clipDistance, _drawDistance);
	glfwSetCursorPos(window, wSize.x / 2, wSize.y / 2);

	// Handle key input to move camera
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		_myPosition += _myRotation * dt * _speed;
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		_myPosition -= _myRotation * dt * _speed;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		_myPosition += right * dt * _speed;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		_myPosition -= right * dt * _speed;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
		_myPosition -= up * dt * _speed;
	}
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
		_myPosition += up * dt * _speed;
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT_CONTROL) == GLFW_PRESS) {
		_speed += 10.0f * dt;
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT) == GLFW_PRESS) {
		_speed -= 10.0f * dt;
	}
}