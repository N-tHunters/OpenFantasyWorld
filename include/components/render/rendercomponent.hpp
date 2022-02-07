#ifndef RENDER_COMPONENT_HPP
#define RENDER_COMPONENT_HPP

#include <vector>

class RenderComponent {
protected:
	static std::vector<RenderComponent*> components;

	RenderComponent();
	// static 
	virtual void Render() = 0;
};

#endif