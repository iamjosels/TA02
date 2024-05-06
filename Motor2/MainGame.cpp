#include "MainGame.h"
#include "Sprite.h"

MainGame::MainGame()
    : window(nullptr), width(800), height(600), gameState(GameState::PLAY),
    imageGenerator(width, height) {
    window = NULL;
    width = 800;
    height = 600;
    gameState = GameState::PLAY;

} // Se inicializa imageGenerator con el ancho y alto de la ventana

void MainGame::init() {
    SDL_Init(SDL_INIT_EVERYTHING);
    window = new Window();
    window->create("Motor WD2M", width, height, 0);
    initShaders();

    // Inicializamos la variable de tiempo transcurrido
    elapsedTime = 0.0f;
}

MainGame::~MainGame() {}

void MainGame::run() {
    init();
    while (gameState != GameState::EXIT) {
        draw();
        processInput();
        update();
    }
}

void MainGame::draw() {
    glClearDepth(1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    program.use();
    GLuint timeLocation = program.getUniformLocation("time");
    glUniform1f(timeLocation, time);
    time += 0.02;
    sprite.draw();
    program.unuse();
    window->swapWindow();
}

void MainGame::update() {
    while (gameState != GameState::EXIT) {
        float deltaTime = 0.016f; 
        elapsedTime += deltaTime;

        // Verificamos si ha pasado el tiempo especificado (2 segundos)
        if (elapsedTime >= 2.0f) {
            // Generamos una nueva imagen
            imageGenerator.generateImage();
            elapsedTime = 0.0f; // Reiniciamos el temporizador
        }

        draw();
        processInput();
    }
}


void MainGame::processInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            gameState = GameState::EXIT;
            break;
        case SDL_MOUSEMOTION:
            cout << " Posicion en X " << event.motion.x
                << " Posicion en Y " << event.motion.y << endl;
            break;
        }
    }
}

void MainGame::initShaders() {
    program.compileShaders("Shaders/colorShaderVert.txt", "Shaders/colorShaderFrag.txt");
    program.addAtribute("vertexPoistion");
    program.addAtribute("vertexColor");
    program.addAtribute("vertexUV");
    program.linkShader();
}


