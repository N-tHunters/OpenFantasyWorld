#include <components/render/rendercomponent.hpp>

RenderComponent::RenderComponent() {
	render_components.push_back(this);
}