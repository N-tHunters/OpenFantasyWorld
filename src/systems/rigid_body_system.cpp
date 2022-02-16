#include <systems/rigid_body_system.hpp>

RigidBodySystem::RigidBodySystem() {

}

void RigidBodySystem::Update(float dt) {
	for (int i = 0; i < RigidBody::GetComponentsCount(); i ++) {
		RigidBody::GetComponent(i)->Update(dt);
	}
}