#include <cstdio>

#include <components/render/mesh.hpp>
#include <assets/model.hpp>
#include <systems/mesh_rendering_system.hpp>
#include <systems/input_system.hpp>

#include <init.hpp>

int main() {
  MeshRenderingSystem mesh_rendering_system;
  InputSystem input_system;

  Init();

  while (!mesh_rendering_system.WindowShouldClose()) {
    input_system.HandleInput();

    mesh_rendering_system.Render();
  }

  return 0;
}