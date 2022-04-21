#ifndef MOUSE_HPP
#define MOUSE_HPP

#include <components/camera_holder.hpp>
#include <components/physics/transform_component.hpp>
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