#ifndef COMPONENTS_RIGID_BODY_HPP
#define COMPONENTS_RIGID_BODY_HPP

#include <components/component.hpp>
#include <components/physics/transform_component.hpp>
#include <glm/glm.hpp>

class RigidBody : public Component<RigidBody> {
	glm::vec3 velocity;
public:
	RigidBody(Entity* entity);
	void Update(float dt);
};

#endif