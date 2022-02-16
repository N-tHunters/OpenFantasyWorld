#include <camera.hpp>

Camera::Camera(glm::vec3 pos, glm::vec3 rot) {
	position = pos;
	rotation = rot;
}

void Camera::Normalize() {
	if (rotation.x > 180.0f) {
		rotation.x = 180.0f;
	} else if (rotation.x < -180.0f) {
		rotation.x = -180.0f;
	}
}