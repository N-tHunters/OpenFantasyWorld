#include <components/physics/rigid_body.hpp>

RigidBody::RigidBody(Entity* entity) : Component(entity, "RigidBody") {
	velocity = glm::vec3(0);
}

void RigidBody::Update(float dt) {
	TransformComponent* transform_component = static_cast<TransformComponent*>(entity->GetComponent("TransformComponent"));
	transform_component->position += velocity * dt;

	if (transform_component->position.y > 1.0f) {
		velocity.y -= 9.81f * dt;
	} else {
		velocity.y = 0.0f;
	}
}