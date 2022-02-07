#ifndef RENDER_MESH_HPP
#define RENDER_MESH_HPP

#include <components/render/rendercomponent.hpp>

class Mesh: public RenderComponent {
public:
  Mesh();
  void Render() override;
};

#endif