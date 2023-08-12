#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <chrono>
#include <cmath>

#include <iostream>

#include "shader.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

unsigned int SCR_WIDTH = 800;
unsigned int SCR_HEIGHT = 600;

float scale = 1;

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Julia", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    } 

    Shader shader;

    float vertices[] = {
        1.0f, 1.0f, 0, 1.0f, -1.0f, 0, -1.0f, -1.0f, 0, -1.0f, 1.0f, 0,
    };
    unsigned int indices[] = {0, 1, 3, 1, 2, 3};
    unsigned int point_array, render_list , index_array;

    glGenVertexArrays(1, &render_list);
    glGenBuffers(1, &index_array);
    glGenBuffers(1, &point_array);

    glBindVertexArray(render_list);

    glBindBuffer(GL_ARRAY_BUFFER, point_array);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_array);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    std::chrono::duration<float, std::ratio<1, 1>> difference;
    float time = 1;

    glBindVertexArray(0);
    while (!glfwWindowShouldClose(window))
    {
        auto begin = std::chrono::high_resolution_clock::now();
        float ratio = (float)SCR_WIDTH / SCR_HEIGHT;

        processInput(window);
        glClearColor(1, 1, 1, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glm::mat4 transform = glm::identity<glm::mat4>();
        transform = glm::scale(transform, glm::vec3(scale, scale/ratio, 1));

        unsigned int TransformLoc = glGetUniformLocation(shader.ID, "transform");
        glUniformMatrix4fv(TransformLoc, 1, GL_FALSE, glm::value_ptr(transform));
        unsigned int DeltaLoc = glGetUniformLocation(shader.ID, "delta");
        glUniform2f(DeltaLoc, sin(time), cos(time));
     
        shader.Use();
        glBindVertexArray(render_list);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
/*
        */
        glfwSwapBuffers(window);
        glfwPollEvents();

        difference = std::chrono::high_resolution_clock::now() - begin;
        time += 1*difference.count();
    }

    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow* window)
{
    float cdelta = 0.001;
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        scale -= cdelta;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        scale += cdelta;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        scale += cdelta;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        scale -= cdelta;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
    SCR_HEIGHT = height;
    SCR_WIDTH = width;
}
