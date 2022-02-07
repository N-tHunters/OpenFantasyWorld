#ifndef RENDER_COMPONENT_HPP
#define RENDER_COMPONENT_HPP

#include <vector>

class RenderComponent {
protected:
	static std::vector<RenderComponent*> components;
	RenderComponent();
	virtual void Render();
};

#endif