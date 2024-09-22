//
// Created by lukesawicki on 9/21/24.
//

#include <bit>
#include <iostream>

#include "yas_application.hpp"
#include "renderer.hpp"

void YasApplication::Initialize() {
  PrepareBasicSettings();
  PrepareRenderingSettings();
}

void YasApplication::CheckEndianness() {
  if constexpr (std::endian::native == std::endian::big) {
    std::cout << "BIG ENDIAN" << std::endl;
    endianness_ = 0;
  }
  else {
    if (std::endian::native == std::endian::little) {
      std::cout << "LITTLE ENDIAN" << std::endl;
      endianness_ = 1;
    }
    else {
      std::cout << "MIXED ENDIAN" << std::endl;
      endianness_ = 2;
    }
  }
}

void YasApplication::PrepareBasicSettings() {

  CheckEndianness();

  if(SDL_Init(SDL_INIT_EVERYTHING)!=0) {
    std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
  } else {
    std::cout  << "Success" << std::endl;
  }

  Uint32 windowFlags = SDL_WINDOW_INPUT_FOCUS | // SDL_WINDOW_BORDERLESS |
    SDL_WINDOW_INPUT_FOCUS | SDL_WINDOW_RESIZABLE |
    SDL_WINDOW_OPENGL; // SDL_WINDOW_ALWAYS_ON_TOP
  window_ = SDL_CreateWindow("YasEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, kScreenWidth, kScreenHeight, windowFlags);

  SDL_SetWindowMinimumSize(window_, kScreenWidth, kScreenHeight);
  //SDL_ShowCursor(SDL_DISABLE);
}

void YasApplication::PrepareRenderingSettings() {
  pixels_table_ = new PixelsTable(kScreenWidth, kScreenHeight, kBlack);
  renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
  SDL_RenderSetLogicalSize(renderer_, kScreenWidth, kScreenHeight);
  SDL_RenderSetIntegerScale(renderer_, SDL_TRUE);
  screen_texture_ = SDL_CreateTexture(renderer_, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STREAMING, kScreenWidth, kScreenHeight);
}

void YasApplication::Update() {
}

void YasApplication::HandleInput() {
}

void YasApplication::HandleKeyboardInput() {
}

void YasApplication::HandleMouseInput() {
}

void YasApplication::Render() {
}

void YasApplication::Run() {
  TimePicker timePicker = TimePicker();
  time_ = timePicker.getSeconds();
  fps_time_ = 0.0F;
  frames_ = 0;

  while (!quit_)
  {
    while (SDL_PollEvent(&event_))
    {
      HandleInput();
    }

    new_time_ = timePicker.getSeconds();
    delta_time_ = new_time_ - time_;
    time_ = new_time_;

    ++frames_;
    fps_time_ = fps_time_ + delta_time_;
    if (fps_time_ >= 1.0F)
    {
      fps_ = frames_ / fps_time_;
      frames_ = 0;
      fps_time_ = 0.0F;
    }

    Update();
    Render();
  }

  Clean();
}

void YasApplication::Clean() {
  delete pixels_table_;
  SDL_DestroyTexture(screen_texture_);
  SDL_DestroyRenderer(renderer_);
  SDL_DestroyWindow(window_);
  SDL_Quit();
}


