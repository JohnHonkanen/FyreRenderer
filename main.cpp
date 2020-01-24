//
// Created by JCH on 19/01/2020.
//

#include <iostream>
#include <GLFW/glfw3.h>
#include "Renderer/Core/FyreRenderer.h"
#include "Renderer/Core/Mesh/Mesh.h"
#include "Renderer/Core/Shader/ShaderManager.h"

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

    Fyre::ShaderManager shaderManager;
    shaderManager.AddShader("basic shader", "Renderer/Assets/vertex.vs", "Renderer/Assets/fragment.fs");
    Fyre::Mesh mesh;

    // render loop
    // -----------
    while (!fyreRenderer.ShouldCloseWindow())
    {
        // input
        // -----
        processInput(fyreRenderer.GetWindowContext().GetWindow());

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        fyreRenderer.ClearRenderFrameBuffers();
        shaderManager.UseShader("basic shader");
        mesh.Render();
        fyreRenderer.SwapRenderFrameBuffers();
        glfwPollEvents();

    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    fyreRenderer.DestroyContext();
    return 0;

    return 0;
}
