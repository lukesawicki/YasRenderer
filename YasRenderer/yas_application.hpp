//
// Created by lukesawicki on 9/21/24.
//

#ifndef YAS_APPLICATION_HPP
#define YAS_APPLICATION_HPP

#include <SDL2/SDL.h>
#include "pixels_table.hpp"
#include "time_picker.hpp"

class YasApplication {
  public:
    static constexpr int kScreenWidth = 640;
    static constexpr int kScreenHeight = 640;

    static YasApplication *GetInstance() {
      if (instance_ != nullptr) {
        return instance_;
      }
      instance_ = new YasApplication();
      return instance_;
    }

    void Initialize();
    void Run();

  private:
    static YasApplication *instance_;
    int endianness_=-1;
    TimePicker timePicker;
    SDL_Window *window_ = nullptr;
    SDL_Renderer *sdl_renderer_ = nullptr;
    SDL_Texture *screen_texture_ = nullptr;
    PixelsTable *pixels_table_ = nullptr;
    SDL_Event event_;
    bool quit_ = false;
    double time_ = 0.0;
    double new_time_ = 0.0;
    double delta_time_ = 0.0;
    double fps_ = 0.0;
    double fps_time_ = 0.0;
    unsigned int frames_ = 0.0;

    struct Input {
      bool left_;
      bool right_;
      bool up_;
      bool down_;
      bool rotate_Counter_clockwise_;
    };

    struct MousePositionChangeInformation {
      double x_ = 0.0;
      double y_ = 0.0;
      bool mouse_moved_ = false;
      bool left_mouse_button_;
      bool right_mouse_button_;
    };

    Input* input_ = new Input();
    MousePositionChangeInformation* mouse_position_change_information_ = new MousePositionChangeInformation();
    float mouse_x_position_ = false;
    float mouse_y_position_ = false;

    Vector2D<float> test_dynamic_line_point_0;
    Vector2D<float> test_dynamic_line_point_1;
    Vector2D<float> test_static_line_point_0;
    Vector2D<float> test_static_line_point_1;

    void CheckEndianness();

    void PrepareBasicSettings();

    void PrepareRenderingSettings();

    void PrepareTestStuff();

    void Update();

    void HandleTestStuff();

    void HandleInput();

    void HandleKeyboardInput();

    void HandleMouseInput();

    void HandleMouseMovement();

    void Render();

    void DrawHudElements();

    void DrawTestStuff();

    void rotateTestLineInToMouseDirection();

    void Clean();
};

#endif //YAS_APPLICATION_HPP
