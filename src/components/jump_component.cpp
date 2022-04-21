#include <components/jump_component.hpp>

JumpComponent::JumpComponent(Entity* entity) : Component<JumpComponent>(entity, "JumpComponent") {
	on_ground = false;
}

void JumpComponent::Jump() {
	if (on_ground) {
		MovementComponent* mc = static_cast<MovementComponent*>(entity->GetComponent("MovementComponent"));
		if (mc->jump) {
			RigidBody* rigidbody = static_cast<RigidBody*>(entity->GetComponent("RigidBody"));
			rigidbody->velocity.y = 3.0f;
		}
	}
}

void JumpComponent::CheckOnGround() {
	TransformComponent* transform = static_cast<TransformComponent*>(entity->GetComponent("TransformComponent"));
	if (transform->position.y <= 1.0f + 0.1f) {
		on_ground = true;
	} else {
		on_ground = false;
	}
}