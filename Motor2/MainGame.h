#pragma once

#include <SDL/SDL.h>
#include <GL/glew.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <memory>
#include "Sprite.h"
#include "GLS_Program.h"
#include "Window.h"
#include "ImageGenerator.h" // Incluimos el encabezado de la clase ImageGenerator

using namespace std;

enum class GameState {
    PLAY, EXIT
};

class MainGame {
private:
    Sprite sprite;
    int width;
    int height;
    Window* window;
    void init();
    void processInput();
    GLS_Program program;
    void initShaders();
    float time = 0;
    int cont = 1;

    // Agregamos una instancia de ImageGenerator
    ImageGenerator imageGenerator;

    // Agregamos una variable para llevar el tiempo transcurrido desde la última generación de imagen
    float elapsedTime;

public:
    MainGame();
    ~MainGame();
    GameState gameState;
    void run();
    void draw();
    void update();
};








