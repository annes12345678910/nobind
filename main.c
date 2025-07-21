#include "raylib.h"
#include "ui.h"

int main() {
    InitWindow(800, 600, "Button Test");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (uiButton((Rectangle){100, 100, 150, 40}, "Hello")) {
            TraceLog(LOG_INFO, "Clicked!");
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
