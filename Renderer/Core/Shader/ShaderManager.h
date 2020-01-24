//
// Created by John Honkanen on 24/01/2020.
//

#ifndef RENDERER_SHADERMANAGER_H
#define RENDERER_SHADERMANAGER_H

#include <unordered_map>
#include "Shader.h"

namespace Fyre {
    class ShaderManager {
    public:
        int AddShader(const char * name, const char * vertexPath, const char * fragmentPath);
        void UseShader(const char * name);
    private:
        std::unordered_map<const char *, Shader> shaders;
    };
}


#endif //RENDERER_SHADERMANAGER_H
