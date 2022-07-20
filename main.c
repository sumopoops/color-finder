#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>



//---------------------------------------------------------------------------------------- GLOBALS

#define MAX_COLORS 5



//---------------------------------------------------------------------------------------- STRUCTS

typedef struct PaletteColor {
    Color color;
    bool locked;
} PaletteColor;



//---------------------------------------------------------------------------------------- FUNCTIONS / PROTOTYPES

void GeneratePallate() {
    // Empty
}

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
    int windowWidth = 1000;
    int windowHeight = 400;

    // Init colors array
    PaletteColor colors[5];
    for (int i=0; i<MAX_COLORS; i++) {
        colors[i].color = (Color){40*i, 40*i, 40*i, 255};
        colors[i].locked = false;
    }

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(windowWidth, windowHeight, "Color Finder");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        // Update
        windowWidth = GetScreenWidth();
        windowHeight = GetScreenHeight();

        // Debug
        for (int i=0; i<MAX_COLORS; i++) printf("COLOR %d R: %d\n\n", i, colors[i].color.r);

        // Keyboard input
        if (IsKeyPressed(KEY_SPACE)) {
            RandomizeColors(colors);
        }

        BeginDrawing();

            ClearBackground(WHITE);

            // Draw colors
            for (int i=0; i<5; i++)
            DrawRectangle(i*(windowWidth/5), 0, (windowWidth/5)+10, (windowHeight), colors[i].color);

        EndDrawing();
    }

    CloseWindow();
}