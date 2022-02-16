#ifndef COMPONENTS_CAMERA_HOLDER_HPP
#define COMPONENTS_CAMERA_HOLDER_HPP

#include <components/component.hpp>
#include <entity.hpp>

class CameraHolder: public Component<CameraHolder> {
public:
	static CameraHolder* camera_holder;
	CameraHolder(Entity*);
};

#endif