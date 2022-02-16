#ifndef MOUSE_HPP
#define MOUSE_HPP

#include <systems/mesh_rendering_system.hpp>
#include <cstdio>

struct Mouse {
	double x;
	double y;
	float sensivity;
	Mouse();
	void Update();
};

#endif