#include <components/render/rendercomponent.hpp>

std::vector<RenderComponent*> RenderComponent::components;

RenderComponent::RenderComponent() {
	RenderComponent::components.push_back(this);
}

void RenderComponent::Render() {}