#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 tex_coord_in;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 cameraRot;
uniform mat4 model;

out float shadow;
out vec2 tex_coord;

void main() {
	shadow = (dot(-normalize((model * vec4(normal, 1)).xyz), vec3(0.0f, 0.0f, -1.0f)) + 1.0f) * 0.5f;
	gl_Position = projection * cameraRot * view * model * vec4(position, 1.0);
    tex_coord = vec2(tex_coord.y, 1.0 - tex_coord_in.y);
}