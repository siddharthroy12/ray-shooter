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
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Shoot!");
    SetExitKey(0);
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    initGlobalState();
    //---------------------------------------------------------------------------------------



    // Main game loop
    while ((!WindowShouldClose()) && globalState->rootNode != NULL)    // Detect window close button or NULL rootNode
    {
        BeginDrawing();
            globalState->rootNode->updateAndRender();
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
    cleanGlobalState();
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}