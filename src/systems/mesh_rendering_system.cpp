#include <systems/mesh_rendering_system.hpp>

Camera* MeshRenderingSystem::camera;
GLFWwindow* MeshRenderingSystem::window;
glm::vec2 MeshRenderingSystem::resolution;
bool MeshRenderingSystem::should_close;

MeshRenderingSystem::MeshRenderingSystem() {
  MeshRenderingSystem::camera = new Camera(glm::vec3(0.0f, 1.0f, 10.0f), glm::vec3(0.0f, -90.0f, 0.0f));
  MeshRenderingSystem::should_close = false;
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  glfwWindowHint(GLFW_MAXIMIZED, GL_TRUE);

  const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
  MeshRenderingSystem::window = glfwCreateWindow(
    mode->width,
    mode->height,
    "OFW",
    glfwGetPrimaryMonitor(),
    nullptr);

  MeshRenderingSystem::resolution = glm::vec2(mode->width, mode->height);
  glfwSetCursorPos(window, (double)resolution.x / 2.0, (double)resolution.y / 2.0);
  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

  glfwMakeContextCurrent(MeshRenderingSystem::window);

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_BLEND);
  glEnable(GL_ALPHA_TEST);
  glEnable(GL_DEBUG_OUTPUT);
  glAlphaFunc(GL_NOTEQUAL, 0.0);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  
  glewExperimental = GL_TRUE;
  glewInit();
}

void MeshRenderingSystem::Render() {
  glClearColor(0.5f, 0.6f, 0.8f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	int component_count = RenderComponent::GetComponentsCount();

	for (int i = 0; i < component_count; i ++) {
		static_cast<RenderComponent*>(RenderComponent::GetComponent(i))->Render();
	}

    glFinish();

	glfwSwapBuffers(MeshRenderingSystem::window);
}

bool MeshRenderingSystem::WindowShouldClose() {
	return glfwWindowShouldClose(MeshRenderingSystem::window) || MeshRenderingSystem::should_close;
}

GLFWwindow* MeshRenderingSystem::GetWindow() {
  return MeshRenderingSystem::window;
}