#include <components/physics/transform_component.hpp>

TransformComponent::TransformComponent(Entity* entity, glm::vec3 position, glm::vec3 rotation) : Component(entity, "TransformComponent") {
	TransformComponent::components.push_back(this);
	this->position = position;
	this->rotation = rotation;
}

TransformComponent::TransformComponent(Entity* entity, glm::vec3 position) :
	TransformComponent(entity, position, glm::vec3(0)) {}