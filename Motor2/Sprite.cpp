#include "Sprite.h"
#include "Vertex.h"
#include "ResourceManager.h"

Sprite::Sprite() : vboID(0) {}

Sprite::~Sprite() {
    if (vboID != 0) {
        glDeleteBuffers(1, &vboID);
    }
}

void Sprite::init(float x, float y, int width, int height, const std::string& texturePath) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;

    if (vboID == 0) {
        glGenBuffers(1, &vboID);
    }

    texture = ResourceManager::getTexture(texturePath); // Cargar la textura de la imagen

    // Definir los vértices del rectángulo texturizado
    Vertex vertexData[6];
    vertexData[0].setPosition(x + width, y + height);
    vertexData[1].setPosition(x, y + height);
    vertexData[2].setPosition(x, y);
    vertexData[3].setPosition(x, y);
    vertexData[4].setPosition(x + width, y);
    vertexData[5].setPosition(x + width, y + height);

    // Definir las coordenadas de textura de los vértices
    vertexData[0].setUV(1.0f, 1.0f);
    vertexData[1].setUV(0.0f, 1.0f);
    vertexData[2].setUV(0.0f, 0.0f);
    vertexData[3].setUV(0.0f, 0.0f);
    vertexData[4].setUV(1.0f, 0.0f);
    vertexData[5].setUV(1.0f, 1.0f);

    // Transferir los datos de los vértices al búfer de vértices
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Sprite::draw() {
    // Bind the texture
    glBindTexture(GL_TEXTURE_2D, texture.id);

    // Bind the vertex buffer
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glEnableVertexAttribArray(0); // Vertex positions
    glEnableVertexAttribArray(1); // UV coordinates

    // Specify vertex attribute data
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));

    // Draw the sprite
    glDrawArrays(GL_TRIANGLES, 0, 6);

    // Disable vertex attributes and unbind buffers
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
