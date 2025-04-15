#pragma once

#include <iostream>
#include <string>

#include "raylib-cpp.hpp"

namespace PA0 {

  class Application final {
  public:
    /**
     * @brief Construct a new Application object
     *
     */
    explicit Application() noexcept;

    /**
     * @brief Destroy the Application object
     *
     */
    ~Application() noexcept;

  public:
    /**
     * @brief Updates the application every frame
     *
     */
    void update();

    /**
     * @brief Renders to display every frame
     *
     */
    void render();

  private:
    int x_pos;
    int y_pos;
    int x_speed;
    int y_speed;

    std::string text;

    raylib::Sound bounce;
    raylib::Font scary;
    raylib::Vector2 textSize;
  };
}  // namespace PA0
