#include <init.hpp>

void Init() {
	Entity* player = new Entity();
	Entity* teapot = new Entity();
	TransformComponent* transform = new TransformComponent(player, glm::vec3(0.0, 0.0, 10.0));
	CameraHolder* camera_holder = new CameraHolder(player);
	Mesh* mesh = new Mesh(teapot, new Model("resources/models/teapot.obj"));
}