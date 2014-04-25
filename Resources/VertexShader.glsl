#version 430 core

layout (std140) uniform Transformation {
    mat4 ModelMatrix;
    mat4 ViewMatrix;
    mat4 ProjectionMatrix;
};

layout(location=0) in vec4 Vertex;
layout(location=1) in vec4 Normal;
layout(location=2) in vec2 TextureCoord;

layout(location=3) in vec4 Color;

out vec4 gl_Position;
out vec4 VertexColor;

void main() {
    gl_Position = ProjectionMatrix * ViewMatrix * ModelMatrix * Vertex;
    VertexColor = Color;
};
