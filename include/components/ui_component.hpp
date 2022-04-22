#ifndef COMPONENTS_UI_COMPONENT_HPP
#define COMPONENTS_UI_COMPONENT_HPP

#include <components/component.hpp>
#include <glm/glm.hpp>

class UIComponent : public Component<UIComponent> {
    protected:
        bool is_visible;
        glm::vec2 position;
    public:
        UIComponent(glm::vec2 position, bool is_visible);
        UIComponent(glm::vec2 position);
        void Render();
        void Show();
        void Hide();
        bool IsVisible();
        glm::vec2 GetPosition();
};

#endif
