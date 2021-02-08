#include "raylib.h"
#include "Globals.hpp"
#include "./context/GlobalContext.hpp"
#include "Node.hpp"
#include <iostream>

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------

    SetTraceLogLevel(LOG_NONE);
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ray Shooter");
    SetExitKey(0);
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    initGlobalState();
    
    // Cursor
    HideCursor();
    Texture texture = LoadTexture("assets/cursor.png");
    Rectangle sourceRec = { 0.0f, 0.0f, texture.width, texture.height };
    Rectangle destRec = { 0.0 , 0.0, texture.width*5, texture.height*5};
    Vector2 origin = { (texture.width*5) /2, (texture.height*5)/2 };
    //---------------------------------------------------------------------------------------



    // Main game loop
    while ((!WindowShouldClose()) && globalState->rootNode != NULL)    // Detect window close button or NULL rootNode
    {
        destRec = { GetMousePosition().x, GetMousePosition().y, texture.width*5, texture.height*5};

        BeginDrawing();
            globalState->rootNode->updateAndRender();
            DrawTexturePro(texture, sourceRec, destRec, origin, 0.0, WHITE);
        EndDrawing();
        if (globalState->change) {
            delete globalState->rootNode;
            globalState->rootNode = globalState->changeTo;
            globalState->change = false;
            globalState->changeTo = NULL;
        } 
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(texture);
    cleanGlobalState();
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}