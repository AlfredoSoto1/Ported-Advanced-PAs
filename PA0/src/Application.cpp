#include "Application.hpp"

using namespace PA0;

Application::Application() noexcept {
  bounce.Load(ASSETS_DIR "bounce.mp3");
  bounce.SetVolume(0.3f);
  scary.Load(ASSETS_DIR "Scary.ttf");
  text = "Welcome to Advanced Programming";
  textSize = scary.MeasureText(text, 20.0f, 0.0f);
  x_speed = 2;
  y_speed = 2;
  x_pos = GetRandomValue(0, GetScreenWidth() - textSize.x);
  y_pos = GetRandomValue(0, GetScreenHeight() - textSize.y);
}

Application::~Application() noexcept {
  bounce.Unload();
  scary.Unload();
}

void Application::update() {
  if (x_pos + (int)textSize.x >= GetScreenWidth() || x_pos <= 0) {
    x_speed *= -1;
    bounce.Play();
  }

  if (y_pos + (int)textSize.y >= GetScreenHeight() || y_pos <= 0) {
    y_speed *= -1;
    bounce.Play();
  }

  x_pos += x_speed;
  y_pos += y_speed;
}

void Application::render() {
  ClearBackground(GRAY);
  scary.DrawText("PA0", (GetScreenWidth() - raylib::TextLength(text)) / 2, 5,
                 20.0f, 0.0f, WHITE);
  scary.DrawText(text, x_pos, y_pos, 20.0f, 0.0f, WHITE);
}
