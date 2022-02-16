#ifndef TRANSFORM_COMPONENT_HPP
#define TRANSFORM_COMPONENT_HPP

#include <glm/glm.hpp>

#include <components/component.hpp>

class TransformComponent : public Component<TransformComponent> {
public:
	TransformComponent(Entity* entity, glm::vec3 position, glm::vec3 rotation);
	TransformComponent(Entity* entity, glm::vec3 position);
	glm::vec3 position;
	glm::vec3 rotation;
};

#endif