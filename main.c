#include "raylib.h"
#define MAX_COLORS 4



//---------------------------------------------------------------------------------------- STRUCTS

typedef struct PaletteColor {
    Color color;
    bool locked;
} PaletteColor;



//---------------------------------------------------------------------------------------- FUNCTIONS / PROTOTYPES

PaletteColor GenerateRandomColor(PaletteColor palCol) {
    if (palCol.locked) return palCol;
    palCol.color.a = 255;
    palCol.color.r = GetRandomValue(0, 255);
    palCol.color.g = GetRandomValue(0, 255);
    palCol.color.b = GetRandomValue(0, 255);
    return palCol;
}

void RandomizeColors(PaletteColor arrayOfColors[]) {
    for (int i=0; i<MAX_COLORS; i++) {
        arrayOfColors[i] = GenerateRandomColor(arrayOfColors[i]);
    }
}



//---------------------------------------------------------------------------------------- MAIN

int main() {

    // Vars
    int windowW = 1000;
    int windowH = 400;

    // Init colors array
    PaletteColor colors[MAX_COLORS];
    for (int i=0; i<MAX_COLORS; i++) {
        colors[i].color = (Color){40*i, 40*i, 40*i, 255};
        colors[i].locked = false;
    }
    colors[1].locked = true; //TEMP

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(windowW, windowH, "Color Finder");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        // Update
        windowW = GetScreenWidth();
        windowH = GetScreenHeight();

        // Keyboard input
        if (IsKeyPressed(KEY_SPACE)) {
            RandomizeColors(colors);
        }

        BeginDrawing();

            ClearBackground(WHITE);

            // Draw colors
            for (int i=0; i<MAX_COLORS; i++)
            DrawRectangle(i*(windowW/MAX_COLORS), 0, (windowW/MAX_COLORS)+10, (windowH), colors[i].color);

        EndDrawing();
    }

    CloseWindow();
}