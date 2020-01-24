//
// Created by John Honkanen on 23/01/2020.
//

#ifndef RENDERER_WINDOW_H
#define RENDERER_WINDOW_H

#include <string>

class GLFWwindow;

namespace Fyre {
    class Window {
        public:
            struct Settings {
                int width, height;
                const char *windowName;
            };

            void Init(Settings settings, void framebuffer_size_callback(GLFWwindow* window, int width, int height));
            void SwapBuffers();
            GLFWwindow * GetWindow();

        private:
        GLFWwindow* window;
    };


}

#endif //RENDERER_WINDOW_H
