#include "./include/raylib.h"
#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

const int screenWidth = 320;
const int screenHeight = 640;

void UpdateDrawFrame(void);

int main(void) {
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    #if defined(PLATFORM_WEB)
        emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
    #else
        SetTargetFPS(60);
        while (!WindowShouldClose()) {
            UpdateDrawFrame();
        }
    #endif
    CloseWindow();
    return 0;
}

void UpdateDrawFrame(void) {
    BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 0, 0, 20, LIGHTGRAY);
    EndDrawing();
}
