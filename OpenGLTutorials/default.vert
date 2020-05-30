#version 330 core

in vec3 aPos;

out vec3 vPos;

uniform mat4 uTransform;
uniform mat4 uView;
uniform mat4 uProjection;

void main()
{
	vPos = aPos;
	gl_Position = uProjection * uView * uTransform * vec4(aPos, 1.0);
}