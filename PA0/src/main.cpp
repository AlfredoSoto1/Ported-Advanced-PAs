
#include "Application.hpp"

using namespace PA0;

int main() {
  // InitWindow(800, 600, "Raylib + CMake");

  // while (!WindowShouldClose()) {
  //   BeginDrawing();
  //   ClearBackground(RAYWHITE);
  //   DrawText("Hello, Raylib!", 300, 280, 20, DARKGRAY);
  //   EndDrawing();
  // }

  // CloseWindow();

  // Can't load sound without this method
  InitAudioDevice();

  // Create the window and OpenGL context & tell the window to use vsync and
  // work on high DPI displays
  raylib::Window window(1024, 724, "Hello Students!!!",
                        FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

  BeginDrawing();
  ClearBackground(GRAY);
  EndDrawing();

  // Create program (if we were loading images & fonts,
  // then you need to make sure that you load() them after window creation)
  Application program = Application();

  // game loop
  while (!WindowShouldClose())  // run the loop untill the user presses ESCAPE
                                // or presses the Close button on the window
  {
    // Update program logic before we draw
    program.update();

    // drawing
    BeginDrawing();

    program.render();

    // end the frame and get ready for the next one  (display frame, poll input,
    // etc...)
    EndDrawing();
  }

  // End the audio device
  CloseAudioDevice();

  // destroy the window and cleanup the OpenGL context
  window.Close();
  return 0;
}
