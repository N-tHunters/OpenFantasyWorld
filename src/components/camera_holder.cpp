#include <components/camera_holder.hpp>

CameraHolder* CameraHolder::camera_holder;

CameraHolder::CameraHolder(Entity* entity): Component<CameraHolder>(entity, "CameraHolder") {
	CameraHolder::camera_holder = this;
	copy_rotation = true;
}