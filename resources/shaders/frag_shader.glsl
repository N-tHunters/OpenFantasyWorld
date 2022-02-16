#version 330 core

in float shadow;

out vec4 color;

void main() {
	color = vec4(vec3(1) * shadow, 1);
}