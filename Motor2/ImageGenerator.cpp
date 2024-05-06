#include "ImageGenerator.h"
#include "Sprite.h"
#include "ResourceManager.h"

ImageGenerator::ImageGenerator(int screenWidth, int screenHeight)
    : screenWidth(screenWidth), screenHeight(screenHeight) {}

ImageGenerator::~ImageGenerator() {}

void ImageGenerator::generateImage() {
   
    Image image;
    image.posX = screenWidth / 2 - 100; // Posición X centrada
    image.posY = screenHeight / 2 - 100; // Posición Y centrada
    image.width = 200; // Ancho de la imagen
    image.height = 200; // Alto de la imagen
    image.texture = ResourceManager::getTexture("Images/fnaf.png"); // Textura de la imagen
    images.push_back(image);
}

void ImageGenerator::draw() {
    // Dibujar todas las imágenes en la posición deseada
    for (const auto& image : images) {
        // Configurar la posición de la imagen en pantalla
        float imagePosX = image.posX;
        float imagePosY = image.posY;

        // Configurar la textura de la imagen
        glBindTexture(GL_TEXTURE_2D, image.texture.id);

        // Crear un sprite temporal para dibujar la imagen en OpenGL
        Sprite tempSprite;

        // Inicializar el sprite temporal con la posición y dimensiones de la imagen
        tempSprite.init(imagePosX, imagePosY, image.width, image.height, "Images/fnaf.png");

        // Dibujar el sprite temporal
        tempSprite.draw();
    }
}




