#include "raylib.h"

int main() {

    // Vars
    Color colors[5];
    int colorCount = 5;
    int windowWidth = 500;
    int windowHeight = 300;

    // Temp
    int testVar = 1;
    for (int i=0; i<5; i++) colors[i] = (Color){i*50, i*50, i*50, 255};

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(windowWidth, windowHeight, "Color Finder");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        // Update
        SetWindowTitle(TextFormat("%i", testVar));
        windowWidth = GetScreenWidth();
        windowHeight = GetScreenHeight();
        testVar++;

        BeginDrawing();

            ClearBackground(WHITE);

            // Draw colors
            for (int i=0; i<5; i++)
            DrawRectangle(i*(windowWidth/5), 0, (windowWidth/5), (windowHeight), colors[i]);

        EndDrawing();
    }

    CloseWindow();
}