#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 cameraRot;
uniform mat4 model;

out float shadow;

void main() {
	shadow = (dot(-normalize((model * vec4(normal, 1)).xyz), vec3(0.0f, 0.0f, -1.0f)) + 1.0f) * 0.5f;
	gl_Position = projection * cameraRot * view * model * vec4(position, 1.0);
}