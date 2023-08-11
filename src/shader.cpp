#include "shader.h"
#include <glad/glad.h>
#include <iostream>
#include <filesystem>
#include <fstream>

const char* load_from_file(const char* name) {
    auto size = std::filesystem::file_size(name);
    std::ifstream io(name, std::ios_base::binary);

    char* data = new char[size + 1];
    io.read(data, size);
    data[size] = '\0';


    io.close();
    return data;
}

Shader::Shader()
{
    const char* fragment_shader_text = load_from_file("FragmentShader.txt");
    const char* vertex_shader_text = load_from_file("VertexShader.txt");

    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertex_shader_text, NULL);
    glCompileShader(vertexShader);
    int  success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragment_shader_text, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    ID = glCreateProgram();
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);
    glLinkProgram(ID);
    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(ID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::LINKERROR\n" << infoLog << std::endl;
    }

    glUseProgram(ID);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    delete[]fragment_shader_text;
    delete[]vertex_shader_text;
}

void Shader::Use()
{
    glUseProgram(ID);
}
