#include "library.h"

#include <iostream>
#include <GLFW/glfw3.h>

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

void hello() {
    std::cout << "Hello, World!" << std::endl;

    glfwSetErrorCallback(error_callback);
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    int a;
    std::cin >> a;
    glfwDestroyWindow(window);
}
