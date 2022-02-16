#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <vector>
#include <string>

class IComponent;

struct Entity {
	static std::vector<Entity*> entities;
	std::vector<IComponent*> components;

	Entity();
	IComponent* GetComponent(std::string name);
};

#endif