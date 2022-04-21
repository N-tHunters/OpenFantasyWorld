#include <camera.hpp>

Camera::Camera(glm::vec3 pos, glm::vec3 rot) {
	position = pos;
	rotation = rot;
}

void Camera::Normalize() {
	if (rotation.x > 90.0f) {
		rotation.x = 90.0f;
	} else if (rotation.x < -90.0f) {
		rotation.x = -90.0f;
	}
}