#ifndef SYSTEMS_CONSTANT_ROTATION_SYSTEM_HPP
#define SYSTEMS_CONSTANT_ROTATION_SYSTEM_HPP

#include <components/physics/constant_rotation_component.hpp>
#include <components/physics/transform_component.hpp>

class ConstantRotationSystem {
public:
	ConstantRotationSystem();
	void Rotate();
};

#endif