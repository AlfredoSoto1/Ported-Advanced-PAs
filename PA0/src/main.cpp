#include "raylib.h"

int main() {
  InitWindow(800, 600, "Raylib + CMake");

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Hello, Raylib!", 300, 280, 20, DARKGRAY);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
