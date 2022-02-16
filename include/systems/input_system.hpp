#ifndef INPUT_SYSTEM_HPP
#define INPUT_SYSTEM_HPP

#include <mouse.hpp>
#include <components/camera_holder.hpp>
#include <components/physics/transform_component.hpp>

class InputSystem {
	static Mouse* mouse;
public:
	InputSystem();
	void HandleInput();
	static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
};

#endif