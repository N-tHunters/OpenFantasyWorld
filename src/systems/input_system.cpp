#include <systems/input_system.hpp>

Mouse* InputSystem::mouse;

InputSystem::InputSystem() {
	InputSystem::mouse = new Mouse();

	glfwSetKeyCallback(MeshRenderingSystem::GetWindow(), InputSystem::KeyCallback);
}

void InputSystem::HandleInput() {
    glfwPollEvents();

	// Mouse
	InputSystem::mouse->Update();
	glm::vec3 pos = static_cast<TransformComponent*>(CameraHolder::camera_holder->entity->GetComponent("TransformComponent"))->position;
	MeshRenderingSystem::camera->position = pos;
}

void InputSystem::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	if (action == GLFW_PRESS) {
		if (key == GLFW_KEY_ESCAPE) {
			MeshRenderingSystem::should_close = true;
		}
	}
}