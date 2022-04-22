#ifndef SYSTEM_MESH_RENDERING_HPP
#define SYSTEM_MESH_RENDERING_HPP

// GLEW
#include <GL/glew.h>

#ifndef GLWF_ALREADY_INCLUDED
#define GLWF_ALREADY_INCLUDED
#include <GLFW/glfw3.h>
#endif

#include <components/render/render_component.hpp>
#include <camera.hpp>
#include <glm/glm.hpp>

class MeshRenderingSystem {
	static GLFWwindow* window;
public:
	static Camera* camera;
	static glm::vec2 resolution;
	static bool should_close;
	MeshRenderingSystem();
	void Render();
	bool WindowShouldClose();
	static GLFWwindow* GetWindow();
};

#endif
