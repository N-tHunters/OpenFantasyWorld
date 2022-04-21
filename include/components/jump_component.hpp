#ifndef COMPONENTS_JUMP_COMPONENT_HPP
#define COMPONENTS_JUMP_COMPONENT_HPP

#include <components/component.hpp>
#include <components/physics/rigid_body.hpp>
#include <components/physics/transform_component.hpp>
#include <components/physics/movement_component.hpp>

class JumpComponent : public Component<JumpComponent> {
public:
	bool on_ground;
	JumpComponent(Entity* entity);
	void Jump();
	void CheckOnGround();
};

#endif