#include <entity.hpp>
#include <components/component.hpp>

std::vector<Entity*> Entity::entities;

Entity::Entity() {
	Entity::entities.push_back(this);
}

IComponent* Entity::GetComponent(std::string name) {
	for (int i = 0; i < components.size(); i ++) {
		if (components[i]->name == name) {
			return components[i];
		}
	}
	return nullptr;
}