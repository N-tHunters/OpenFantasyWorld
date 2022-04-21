#include <cstdio>

#include <components/render/mesh.hpp>
#include <assets/model.hpp>
#include <systems/mesh_rendering_system.hpp>
#include <systems/input_system.hpp>
#include <systems/movement_system.hpp>
#include <systems/rigid_body_system.hpp>
#include <systems/constant_rotation_system.hpp>
#include <systems/jump_system.hpp>

#include <init.hpp>

int main() {
  MeshRenderingSystem mesh_rendering_system;
  InputSystem input_system;
  MovementSystem movement_system;
  RigidBodySystem rigid_body_system;
  ConstantRotationSystem constant_rotation_system;
  JumpSystem jump_system;

  Init();

  input_system.CreatePlayerComponent();

  while (!mesh_rendering_system.WindowShouldClose()) {
    input_system.HandleInput();

    constant_rotation_system.Rotate();
    movement_system.Move();
    jump_system.Jump();
    rigid_body_system.Update(0.1f);

    mesh_rendering_system.Render();
  }

  return 0;
}