//
// Created by John Honkanen on 24/01/2020.
//

#ifndef RENDERER_FYRERENDERER_H
#define RENDERER_FYRERENDERER_H

#include "Core/window.h"

namespace Fyre {
    class Renderer {
    public:
        int Init(Window::Settings settings);
        int ClearRenderFrameBuffers();
        int SwapRenderFrameBuffers();
        int DestroyContext();
        bool ShouldCloseWindow();

        Window & GetWindowContext();
    private:
        Window window;

        int SetupWindow(Window::Settings settings, void framebuffer_size_callback(GLFWwindow* window, int width, int height));
    };
}



#endif //RENDERER_FYRERENDERER_H
