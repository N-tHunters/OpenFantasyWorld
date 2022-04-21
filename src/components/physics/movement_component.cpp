#include <components/physics/movement_component.hpp>

MovementComponent::MovementComponent(Entity* entity) : Component(entity, "MovementComponent") {
	moving = false;
	speed = 2.0f;
}

void MovementComponent::ApplySpeed() {
	RigidBody* ridig_body = static_cast<RigidBody*>(entity->GetComponent("RigidBody"));
	if (moving) {
		float transform_rotation = static_cast<TransformComponent*>(entity->GetComponent("TransformComponent"))->rotation.y;
		ridig_body->velocity.x = cos((direction + transform_rotation - 90.0f) * PI / 180.0f) * speed;
		ridig_body->velocity.z = sin((direction + transform_rotation - 90.0f) * PI / 180.0f) * speed;
	} else {
		ridig_body->velocity.x = 0.0f;
		ridig_body->velocity.z = 0.0f;
	}
}