#include <init.hpp>

void Init() {
	Entity* teapot = new Entity();
	Mesh* mesh = new Mesh(teapot, new Model("resources/models/teapot.obj"), Texture::GetTexture("marble"));
	ConstantRotation* cr = new ConstantRotation(teapot);
	TransformComponent* tc = new TransformComponent(teapot, glm::vec3(0.0));
	InputSystem::player = new Entity();
	PlayerComponent* pc = new PlayerComponent(InputSystem::player);
	MovementComponent* mc = new MovementComponent(InputSystem::player);
	RigidBody* rb = new RigidBody(InputSystem::player);
	TransformComponent* transform = new TransformComponent(InputSystem::player, glm::vec3(0.0, 0.0, 10.0));
	CameraHolder* camera_holder = new CameraHolder(InputSystem::player);
	JumpComponent* jump_component = new JumpComponent(InputSystem::player);
}