//
// Created by JCH on 19/01/2020.
//

#include <iostream>
#include <GLFW/glfw3.h>
#include "Renderer/Core/FyreRenderer.h"

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main(){
    // glfw: initialize and configure
    // ------------------------------
    auto fyreRenderer = Fyre::Renderer();
    auto windowSettings = Fyre::Window::Settings{500, 500, "Fyre Engine Demo"};

    if(fyreRenderer.Init(windowSettings) == 1 ) {
        return 1;
    };

    // render loop
    // -----------
    while (!fyreRenderer.ShouldCloseWindow())
    {
        // input
        // -----
        processInput(fyreRenderer.GetWindowContext().GetWindow());

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        fyreRenderer.RenderFrame();
        glfwPollEvents();

    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    fyreRenderer.DestroyContext();
    return 0;

    return 0;
}
