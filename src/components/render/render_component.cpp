#include <components/render/render_component.hpp>

RenderComponent::RenderComponent(Entity* entity, std::string name): Component(entity, name) {
	RenderComponent::components.push_back(this);
}

void RenderComponent::Render() {}