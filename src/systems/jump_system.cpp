#include <systems/jump_system.hpp>

JumpSystem::JumpSystem() {}

void JumpSystem::Jump() {
	int component_count = JumpComponent::GetComponentsCount();
	for (int i = 0; i < component_count; i ++) {
		static_cast<JumpComponent*>(JumpComponent::GetComponent(i))->CheckOnGround();
		static_cast<JumpComponent*>(JumpComponent::GetComponent(i))->Jump();
	}
}