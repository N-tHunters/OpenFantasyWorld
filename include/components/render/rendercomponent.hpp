#ifndef RENDER_COMPONENT_HPP
#define RENDER_COMPONENT_HPP

class RenderComponent {
protected:
	static components;

	RenderComponent();
	static 
	virtual void render();
};

#endif