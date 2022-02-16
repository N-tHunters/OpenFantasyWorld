#ifndef COMPONENTS_I_COMPONENT_HPP
#define COMPONENTS_I_COMPONENT_HPP

class Entity;

class IComponent {
public:
	std::string name;
	Entity* entity;
};

#endif