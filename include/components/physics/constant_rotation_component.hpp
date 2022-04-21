#ifndef COMPONENTS_CONSTANT_ROTATION_COMPONENT_HPP
#define COMPONENTS_CONSTANT_ROTATION_COMPONENT_HPP

#include <components/component.hpp>

class ConstantRotation : public Component<ConstantRotation> {
public:
	ConstantRotation(Entity*);
};

#endif