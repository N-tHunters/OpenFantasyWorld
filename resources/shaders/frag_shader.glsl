#version 330 core

in float shadow;
in vec2 tex_coord;

uniform sampler2D tex;

out vec4 color;

void main() {
	color = texture(tex, tex_coord);
    color.rgb *= shadow;
}