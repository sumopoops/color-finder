#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_COLORS 5

//---------------------------------------------------------------------------------------- GLOBALS

Color colors[MAX_COLORS];



//---------------------------------------------------------------------------------------- FUNCTIONS

void GeneratePallate() {
    // Empty
}

void GenerateRandomPallate() {
    for (int i=0; i<5; i++) {
        colors[i].a = 255;
        colors[i].r = GetRandomValue(0, 255);
        colors[i].g = GetRandomValue(0, 255);
        colors[i].b = GetRandomValue(0, 255);
    }
}



//---------------------------------------------------------------------------------------- MAIN

int main() {

    // Vars
    int windowWidth = 1000;
    int windowHeight = 400;
    //int colorCount = 5;
    char** colorNames = malloc(6);

    // Temp
    for (int i=0; i<5; i++) colors[i] = (Color){i*50, i*50, i*50, 255};
    colorNames[0] = "HHHHH";
    colorNames[1] = "HHHHH";
    colorNames[2] = "HHHHH";
    printf("colorName[0] = %s, colorName[1] = %s\n\n", colorNames[0], colorNames[1]);

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(windowWidth, windowHeight, "Color Finder");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        // Update
        windowWidth = GetScreenWidth();
        windowHeight = GetScreenHeight();

        // Keyboard input
        if (IsKeyPressed(KEY_SPACE)) {
            GenerateRandomPallate();
        }

        BeginDrawing();

            ClearBackground(WHITE);

            // Draw colors
            for (int i=0; i<5; i++)
            DrawRectangle(i*(windowWidth/5), 0, (windowWidth/5), (windowHeight), colors[i]);

        EndDrawing();
    }

    CloseWindow();
}