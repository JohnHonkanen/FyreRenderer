//
// Created by John Honkanen on 24/01/2020.
//

#include "Shader.h"
#include <glad/glad.h>

void Fyre::Shader::Use() {
    glUseProgram(shaderId);
}

Fyre::Shader::Shader(unsigned int id, const char *name) : shaderId(id), name(name)  {

}
