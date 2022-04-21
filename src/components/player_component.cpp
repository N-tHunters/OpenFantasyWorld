#include <components/player_component.hpp>

PlayerComponent* PlayerComponent::player_component;

PlayerComponent::PlayerComponent(Entity* entity) : Component(entity, "PlayerComponent") {
	PlayerComponent::player_component = this;
	x = 0;
	y = 0;
	jump = false;
}

void PlayerComponent::ApplyMovement() {
	MovementComponent* mc = static_cast<MovementComponent*>(entity->GetComponent("MovementComponent"));
	if (mc == nullptr) {
		printf("Error: MovementComponent in PlayerComponent::ApplyMovement is nullptr\n");
		return;
	}
	if (x == 0) {
		if (y == 0) {
			mc->moving = false;
		} else if (y < 0) {
			mc->direction = 180.0f;
		} else {
			mc->direction = 0.0f;
		}
	} else if (x < 0) {
		if (y == 0) {
			mc->direction = 270.0f;
		} else if (y < 0) {
			mc->direction = 225.0f;
		} else {
			mc->direction = 315.0f;
		}
	} else {
		if (y == 0) {
			mc->direction = 90.0f;
		} else if (y < 0) {
			mc->direction = 135.0f;
		} else {
			mc->direction = 45.0f;
		}
	}

	mc->jump = jump;

	if (x != 0 || y != 0) {
		mc->moving = true;
	}
}