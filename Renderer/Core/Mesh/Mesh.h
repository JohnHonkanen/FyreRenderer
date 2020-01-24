//
// Created by John Honkanen on 27/01/2020.
//

#ifndef RENDERER_MESH_H
#define RENDERER_MESH_H


namespace Fyre {
    class Mesh {
    public:
        Mesh();
        void Render();

    protected:
        float * vertices;

        unsigned int vao;
        unsigned int vbo;
    };
}
#endif //RENDERER_MESH_H
