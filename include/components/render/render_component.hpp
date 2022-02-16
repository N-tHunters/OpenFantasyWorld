#ifndef RENDER_COMPONENT_HPP
#define RENDER_COMPONENT_HPP

#include <vector>

#include <components/component.hpp>

/**
 * @brief      Base component that renders
 */
class RenderComponent : public Component<RenderComponent> {
protected:
	RenderComponent(Entity*, std::string); ///< Constructor, adds itself to vector of components
public:
	virtual void Render(); ///< virtual render function, renders element on screen
};

#endif