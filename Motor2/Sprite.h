#pragma once

#include <GL/glew.h>
#include <string>
#include "GLTexture.h"

class Sprite {
private:
    float x, y;
    int width, height;
    GLuint vboID;
    GLTexture texture; // Nuevo miembro para almacenar la textura de la imagen
public:
    Sprite();
    ~Sprite();
    void init(float x, float y, int width, int height, const std::string& texturePath);
    void draw();
};
