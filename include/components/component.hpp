#ifndef COMPONENTS_COMPONENT_HPP
#define COMPONENTS_COMPONENT_HPP

#include <string>

#include <components/i_component.hpp>
#include <entity.hpp>

template <typename T>
class Component : public IComponent {
protected:
	static std::vector<Component<T>*> components;
public:
	Component(Entity*, std::string);

	static int GetComponentsCount();
	static Component<T>* GetComponent(int id);
};

template<typename T>
std::vector<Component<T>*> Component<T>::components;

template<typename T>
Component<T>::Component(Entity* entity, std::string name) {
	this->entity = entity;
	this->name = name;
	this->entity->components.push_back(this);
	Component<T>::components.push_back(this);
}

template<typename T>
int Component<T>::GetComponentsCount() {
	return components.size();
}

template<typename T>
Component<T>* Component<T>::GetComponent(int id) {
	return components[id];
}

#endif