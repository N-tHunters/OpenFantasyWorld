#ifndef SYSTEMS_RIGID_BODY_SYSTEM_HPP
#define SYSTEMS_RIGID_BODY_SYSTEM_HPP

#include <components/physics/rigid_body.hpp>

class RigidBodySystem {
public:
	RigidBodySystem();
	void Update(float dt);
};

#endif