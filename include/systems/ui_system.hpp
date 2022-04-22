#ifndef SYSTEMS_UI_SYSTEM_HPP
#define SYSTEMS_UI_SYSTEM_HPP


// GLEW
#include <GL/glew.h>

#ifndef GLWF_ALREADY_INCLUDED
#define GLWF_ALREADY_INCLUDED
#include <GLFW/glfw3.h>
#endif

#include <components/ui_component.hpp>
#include <glm/glm.hpp>


class UiSystem {
    private:
        static GLFWwindow* window;
    public:
        static glm::vec2 resolution;
        UiSystem();
        void Render();
};

#endif
