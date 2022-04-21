#ifndef COMPONENTS_MOVEMENT_COMPONENT_HPP
#define COMPONENTS_MOVEMENT_COMPONENT_HPP

#define PI 3.1415926535

#include <math.h>
#include <components/component.hpp>
#include <components/physics/rigid_body.hpp>

class MovementComponent : public Component<MovementComponent> {
public:
	float speed;
	float direction;
	bool moving;
	bool jump;

	MovementComponent(Entity*);
	void ApplySpeed();
};

#endif