#version 330 core

in vec3 aPos;
in vec4 aColor;

out vec4 vColor;

void main()
{
	vColor = aColor;
	gl_Position = vec4(aPos, 1.0);
}