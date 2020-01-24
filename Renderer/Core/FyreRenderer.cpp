//
// Created by John Honkanen on 24/01/2020.
//

#include "FyreRenderer.h"
#include <glad/glad.h>
#include <iostream>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}



int Fyre::Renderer::Init(Fyre::Window::Settings settings) {
    SetupWindow(settings, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        ::std::cout << "Failed to initialize GLAD" << ::std::endl;
        return 1;
    }

    return 0;
}

int Fyre::Renderer::SetupWindow(Fyre::Window::Settings settings,
                                void (*framebuffer_size_callback)(GLFWwindow *, int, int)) {
    window = Window();
    window.Init(settings, framebuffer_size_callback);
    return 0;
}

int Fyre::Renderer::RenderFrame() {
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window.GetWindow());

    return 0;
}

int Fyre::Renderer::DestroyContext() {
    glfwTerminate();
    return 0;
}

bool Fyre::Renderer::ShouldCloseWindow() {
    return glfwWindowShouldClose(window.GetWindow());
}

Fyre::Window &Fyre::Renderer::GetWindowContext() {
    return window;
}
