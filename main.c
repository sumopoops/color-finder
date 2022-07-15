#include "raylib.h"

int main() {

    // Vars
    Color colors[5];

    // Temp
    int testVar = 1;
    for (int i=0; i<5; i++) colors[i] = (Color){i*50, i*50, i*50, 255};

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(500, 300, "Color Finder");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        // Update
        SetWindowTitle(TextFormat("%i", testVar));
        testVar++;

        BeginDrawing();

            ClearBackground(WHITE);

            // Draw colors
            for (int i=0; i<5; i++)
            DrawRectangle(i*100, 0, 100, 300, colors[i]);

        EndDrawing();
    }

    CloseWindow();
}