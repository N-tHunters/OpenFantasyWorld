#ifndef RENDER_MESH_HPP
#define RENDER_MESH_HPP

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Components
#include <components/render/render_component.hpp>

// Assets
#include <assets/shader.hpp>
#include <assets/model.hpp>

// Systems
#include <systems/mesh_rendering_system.hpp>

/**
 * @brief      3D object that renders on screen
 */
class Mesh: public RenderComponent {
  Shader* shader;
  GLuint VAO, VBO, EBO;
  int size;
public:
  Mesh(Entity* entity, Model* model);
  /**
   * @brief      Draws mesh
   */
  void Render() override;
};

#endif