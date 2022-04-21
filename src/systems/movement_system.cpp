#include <systems/movement_system.hpp>

MovementSystem::MovementSystem() {}

void MovementSystem::Move() {
	int component_count = MovementComponent::GetComponentsCount();
	for (int i = 0; i < component_count; i ++) {
		static_cast<MovementComponent*>(MovementComponent::GetComponent(i))->ApplySpeed();
	}
}