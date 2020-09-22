#version 330 core

uniform mat4 MVP;

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec2 UV;
layout(location = 2) in vec3 normal;

void main(){ 
    gl_Position = MVP * vec4(vertexPosition_modelspace, 1);
}