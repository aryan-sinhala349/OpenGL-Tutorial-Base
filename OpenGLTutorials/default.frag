#version 330 core

in vec3 vPos;

out vec4 color;

void main()
{
	color = vec4(vPos + 0.5, 1.0);
}