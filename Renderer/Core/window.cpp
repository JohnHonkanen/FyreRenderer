//
// Created by John Honkanen on 23/01/2020.
//

#include "window.h"
#include <iostream>
#include <GLFW/glfw3.h>

void Fyre::Window::Init(Settings settings,  void (*framebuffer_size_callback)(GLFWwindow *, int, int)) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif
    // glfw window creation
    // --------------------
    window = glfwCreateWindow(settings.width, settings.height, settings.windowName, NULL, NULL);
    if (window == NULL)
    {
        ::std::cout << "Failed to create GLFW window" << ::std::endl;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

void Fyre::Window::SwapBuffers() {
    glfwSwapBuffers(window);
}

GLFWwindow *Fyre::Window::GetWindow() {
        return window;
}

