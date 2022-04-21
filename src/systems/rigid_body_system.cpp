#include <systems/rigid_body_system.hpp>

RigidBodySystem::RigidBodySystem() {

}

void RigidBodySystem::Update(float dt) {
	int components_count = RigidBody::GetComponentsCount();
	for (int i = 0; i < components_count; i ++) {
		static_cast<RigidBody*>(RigidBody::GetComponent(i))->Update(dt);
	}
}