#include <mouse.hpp>

Mouse::Mouse() {
	sensivity = 0.1f;
}

void Mouse::Update() {
	double prev_x = x;
	double prev_y = y;
	glfwGetCursorPos(MeshRenderingSystem::GetWindow(), &x, &y);
	double dx = x - prev_x;
	double dy = y - prev_y;

	MeshRenderingSystem::camera->rotation.x += dy * sensivity;
	MeshRenderingSystem::camera->rotation.y += dx * sensivity;
	MeshRenderingSystem::camera->Normalize();
}