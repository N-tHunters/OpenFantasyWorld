#include <systems/input_system.hpp>

Mouse* InputSystem::mouse;
Entity* InputSystem::player;

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

	// Movement
	PlayerComponent::player_component->ApplyMovement();
}

void InputSystem::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	if (action == GLFW_PRESS) {
		if (key == GLFW_KEY_ESCAPE) {
			MeshRenderingSystem::should_close = true;
		} else if (key == GLFW_KEY_W) {
			PlayerComponent::player_component->y += 1;
		} else if (key == GLFW_KEY_A) {
			PlayerComponent::player_component->x -= 1;
		} else if (key == GLFW_KEY_S) {
			PlayerComponent::player_component->y -= 1;
		} else if (key == GLFW_KEY_D) {
			PlayerComponent::player_component->x += 1;
		} else if (key == GLFW_KEY_SPACE) {
			PlayerComponent::player_component->jump = true;
		}
	} else if (action == GLFW_RELEASE) {
		if (key == GLFW_KEY_W) {
			PlayerComponent::player_component->y -= 1;
		} else if (key == GLFW_KEY_A) {
			PlayerComponent::player_component->x += 1;
		} else if (key == GLFW_KEY_S) {
			PlayerComponent::player_component->y += 1;
		} else if (key == GLFW_KEY_D) {
			PlayerComponent::player_component->x -= 1;
		} else if (key == GLFW_KEY_SPACE) {
			PlayerComponent::player_component->jump = false;
		}
	}
}

void InputSystem::CreatePlayerComponent() {
	PlayerComponent* pc = new PlayerComponent(InputSystem::player);
}