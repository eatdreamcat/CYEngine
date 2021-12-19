#version 330 core

layout(location = 7) in vec4 aColor;
layout(location = 8) in vec3 aPos;
layout (location = 9) in vec3 aNormal;
layout(location = 10) in vec2 aTexCoord;
uniform vec4 ourColor;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec4 vertexColor;
out vec2 TexCoord;
out vec3 Normal;
out vec3 FragPos;
void main() {
    gl_Position = projection*view*model*vec4(aPos, 1.0);
    vertexColor = aColor;
    TexCoord = aTexCoord;
    FragPos = vec3(model * vec4(aPos, 1.0f));
    Normal = mat3(transpose(inverse(model)))*aNormal;
}