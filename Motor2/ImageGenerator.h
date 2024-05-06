#pragma once

#include <vector>
#include "GLTexture.h"
#include "Sprite.h"

class Image {
public:
    float posX;
    float posY;
    int width;
    int height;
    GLTexture texture;
};

class ImageGenerator {
public:
    ImageGenerator(int screenWidth, int screenHeight);
    ~ImageGenerator();

    void generateImage();
    void draw();

private:
    int screenWidth;
    int screenHeight;
    std::vector<Image> images;
};

