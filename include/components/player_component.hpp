#ifndef COMPONENTS_PLAYER_COMPONENT_HPP
#define COMPONENTS_PLAYER_COMPONENT_HPP

#include <components/component.hpp>
#include <components/physics/movement_component.hpp>
#include <components/physics/rigid_body.hpp>
#include <components/jump_component.hpp>

class PlayerComponent: public Component<PlayerComponent> {
public:
	int8_t x, y;
	bool jump;
	static PlayerComponent* player_component;
	PlayerComponent(Entity* entity);
	void ApplyMovement();
};

#endif