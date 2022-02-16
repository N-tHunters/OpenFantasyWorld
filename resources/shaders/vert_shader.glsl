#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 cameraRot;

out float shadow;

void main() {
	shadow = (dot(-normalize(normal), vec3(0.0f, 0.0f, -1.0f)) + 1.0f) * 0.5f;
	gl_Position = projection * cameraRot * view * vec4(position, 1.0);
}