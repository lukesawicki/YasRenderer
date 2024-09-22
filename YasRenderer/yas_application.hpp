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
    constexpr int kScreenWidth = 640;
    constexpr int kScreenHeight = 480;

    static YasApplication *GetInstance() {
      if (instance_ != nullptr) {
        return instance_;
      }
      instance_ = new YasApplication();
      return instance_;
    }

    void Initialize();

  private:
    static YasApplication *instance_;
    int endianness_;
    TimePicker timePicker;
    SDL_Window *window_;
    SDL_Renderer *renderer_;
    SDL_Texture *screen_texture_;
    PixelsTable *pixels_table_;
    SDL_Event event_;
    bool quit_ = false;
    double time_;
    double new_time_;
    double delta_time_;
    double fps_;
    double fps_time_;
    unsigned int frames_;

    void CheckEndianness();

    void PrepareBasicSettings();

    void PrepareRenderingSettings();

    void Update();

    void HandleInput();

    void HandleKeyboardInput();

    void HandleMouseInput();

    void Render();

    void Run();

    void Clean();
};

#endif //YAS_APPLICATION_HPP
