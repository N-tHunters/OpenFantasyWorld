#ifndef COMPONENTS_RIGID_BODY_HPP
#define COMPONENTS_RIGID_BODY_HPP

#include <components/component.hpp>
#include <components/physics/transform_component.hpp>
#include <glm/glm.hpp>

class RigidBody : public Component<RigidBody> {
public:
	glm::vec3 velocity;

	RigidBody(Entity* entity);
	void Update(float dt);
	void SetSpeed(glm::vec3);
};

#endif