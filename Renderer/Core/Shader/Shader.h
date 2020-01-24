//
// Created by John Honkanen on 24/01/2020.
//

#ifndef RENDERER_SHADER_H
#define RENDERER_SHADER_H

namespace Fyre {
    class Shader {
    public:
        Shader(): shaderId(-1), name("null"){}
        Shader(unsigned int id, const char * name);
        void Use();
        const char * GetName() { return name; }
    private:
        const char * name;
        int shaderId;
    };
}

#endif //RENDERER_SHADER_H
