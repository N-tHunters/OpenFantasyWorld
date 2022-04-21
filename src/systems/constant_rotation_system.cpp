#include <systems/constant_rotation_system.hpp>

ConstantRotationSystem::ConstantRotationSystem() {
}

void ConstantRotationSystem::Rotate() {
	int component_count = ConstantRotation::GetComponentsCount();
	for (int i = 0; i < component_count; i ++) {
		Entity* entity = static_cast<ConstantRotation*>(ConstantRotation::GetComponent(i))->entity;
		static_cast<TransformComponent*>(entity->GetComponent("TransformComponent"))->rotation.y += 1.0f;
	}
}