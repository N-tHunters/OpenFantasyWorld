#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/glm.hpp>

class Camera {
public:
	Camera(glm::vec3, glm::vec3);
	void Normalize();
	glm::vec3 position;
	glm::vec3 rotation;
};

#endif