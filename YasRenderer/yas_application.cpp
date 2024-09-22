//
// Created by lukesawicki on 9/21/24.
//

#include <bit>
#include <iostream>

#include "yas_application.hpp"
#include "renderer.hpp"

YasApplication* YasApplication::instance_ = nullptr;

void YasApplication::Initialize() {
  PrepareBasicSettings();
  PrepareRenderingSettings();
  PrepareTestStuff();
}

void YasApplication::CheckEndianness() {
  if constexpr (std::endian::native == std::endian::big) {
    std::cout << "BIG ENDIAN" << std::endl;
    endianness_ = 0;
  } else {
    if (std::endian::native == std::endian::little) {
      std::cout << "LITTLE ENDIAN" << std::endl;
      endianness_ = 1;
    } else {
      std::cout << "MIXED ENDIAN" << std::endl;
      endianness_ = 2;
    }
  }
}

void YasApplication::PrepareBasicSettings() {
  CheckEndianness();

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
  } else {
    std::cout << "Success" << std::endl;
  }

  Uint32 windowFlags = SDL_WINDOW_INPUT_FOCUS | // SDL_WINDOW_BORDERLESS |
                       SDL_WINDOW_INPUT_FOCUS | SDL_WINDOW_RESIZABLE |
                       SDL_WINDOW_OPENGL; // SDL_WINDOW_ALWAYS_ON_TOP
  window_ = SDL_CreateWindow("YasEngine", SDL_WINDOWPOS_CENTERED,
                             SDL_WINDOWPOS_CENTERED, kScreenWidth,
                             kScreenHeight, windowFlags);

  SDL_SetWindowMinimumSize(window_, kScreenWidth, kScreenHeight);
  SDL_ShowCursor(SDL_DISABLE);
}

void YasApplication::PrepareRenderingSettings() {
  pixels_table_ = new PixelsTable(kScreenWidth, kScreenHeight, kBlack);
  sdl_renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
  SDL_RenderSetLogicalSize(sdl_renderer_, kScreenWidth, kScreenHeight);
  SDL_RenderSetIntegerScale(sdl_renderer_, SDL_TRUE);
  screen_texture_ = SDL_CreateTexture(sdl_renderer_, SDL_PIXELFORMAT_ABGR8888,
                                      SDL_TEXTUREACCESS_STREAMING, kScreenWidth,
                                      kScreenHeight);
}

void YasApplication::PrepareTestStuff() {
  test_static_line_point_0.x_ = 0;
  test_static_line_point_0.y_ = 0;
  test_static_line_point_1.x_ = 640;
  test_static_line_point_1.y_ = 480;
}

void YasApplication::Update() {
  HandleTestStuff();
}

void YasApplication::HandleTestStuff() {
  if (mouse_position_change_information_->mouse_moved_)
  {
    rotateTestLineInToMouseDirection();
  }
}

void YasApplication::HandleInput() {
  if (event_.type == SDL_QUIT) {
    quit_ = true;
  } else {
    HandleKeyboardInput();
    HandleMouseInput();
  }
}

void YasApplication::HandleKeyboardInput() {
  if (event_.type == SDL_KEYDOWN)
  {
    switch (event_.key.keysym.sym)
    {
      case SDLK_ESCAPE:
        ;
      break;
      case SDLK_SPACE:
        ;
      break;
      case SDLK_w:
        input_->up_ = true;
      break;
      case SDLK_s:
        input_->down_ = true;
      break;
      case SDLK_a:
        input_->left_ = true;
      break;
      case SDLK_d:
        input_->right_ = true;
      break;
      case SDLK_RETURN:
        ;
      break;
      case SDLK_TAB:
        ;
      break;
      default:
        ;
    }
  }

  if (event_.type == SDL_KEYUP) {
    switch (event_.key.keysym.sym) {
      case SDLK_w:
        input_->up_ = false;
      break;
      case SDLK_s:
        input_->down_ = false;
      break;
      case SDLK_a:
        input_->left_ = false;
      break;
      case SDLK_d:
        input_->right_ = false;
      break;
      default:
        ;
    }
  }
}

void YasApplication::HandleMouseInput() {
  if (event_.type == SDL_MOUSEMOTION)
  {
    HandleMouseMovement();
  }
  if (event_.type == SDL_MOUSEBUTTONDOWN && event_.button.button == SDL_BUTTON_LEFT)
  {
    ;
  }

  if (event_.type == SDL_MOUSEBUTTONUP && event_.button.button == SDL_BUTTON_LEFT)
  {
    ;
  }
}

void YasApplication::HandleMouseMovement()
{
  int x;
  int y;
  SDL_GetMouseState(&x, &y);
  mouse_position_change_information_->mouse_moved_ = true;
  mouse_position_change_information_->x_ = x;
  mouse_position_change_information_->y_ = y;
  mouse_x_position_ = static_cast<float>(mouse_position_change_information_->x_);
  mouse_y_position_ = static_cast<float>(mouse_position_change_information_->y_);

  WindowPositionToCartesianPosition(mouse_x_position_, mouse_y_position_, kScreenWidth, kScreenHeight);
}

void YasApplication::Render() {

  pixels_table_->ClearColor(kBlack);

  DrawHudElements();

  SDL_UpdateTexture(screen_texture_ , NULL, pixels_table_->pixels_, kScreenWidth * 4);
  SDL_RenderCopyExF(sdl_renderer_, screen_texture_, NULL, NULL, 0, NULL, SDL_RendererFlip::SDL_FLIP_NONE); //SDL_FLIP_VERTICAL);
  SDL_RenderPresent(sdl_renderer_);
}

void YasApplication::DrawHudElements() {
  DrawCrossHair(mouse_x_position_, mouse_y_position_, *pixels_table_, false, kGreen);
  DrawTestStuff();
}

void YasApplication::DrawTestStuff() {
  // Vector2D<float> start_point = Vector2D<float>(test_line_point_0_x_, test_line_point_0_y_);
  // Vector2D<float> end_point = Vector2D<float>(test_line_point_1_x_, test_line_point_1_y_);
  // DrawLine(start_point, end_point, *pixels_table_, kYellow);
  DrawLine(test_static_line_point_0, test_static_line_point_1, *pixels_table_, kRed);
}

void YasApplication::rotateTestLineInToMouseDirection() {
  if (mouse_x_position_ <= kScreenWidth && mouse_y_position_ <= kScreenHeight)
  {
    float current_x_mouse_possition = mouse_x_position_;
    float current_y_mouse_possition = mouse_y_position_;

    //WindowPositionToCartesianPosition(current_x_mouse_possition, current_y_mouse_possition, kScreenWidth, kScreenHeight);

    Vector2D<float> currentMousePosition = Vector2D<float>(current_x_mouse_possition, current_y_mouse_possition);

    Vector2D<float> beginning_of_test_line = Vector2D<float>(test_line_point_0_x_, test_line_point_0_y_);

    Vector2D<float>  end_of_the_test_line = Vector2D<float>(test_line_point_1_x_, test_line_point_1_y_);

    Vector2D<float> direction_in_local_coordinates_system = Vector2D<float>::CreateUnitVectorFromBoundVector(currentMousePosition, beginning_of_test_line);

    float angleBetweenCurrentAndMouse = Vector2D<float>::AngleBetweenVectors(end_of_the_test_line, direction_in_local_coordinates_system);

    Vector2D<float>::RotateVectorOverTheAngle(&end_of_the_test_line, angleBetweenCurrentAndMouse);
    test_line_point_1_x_ = end_of_the_test_line.x_;
    test_line_point_1_y_ = end_of_the_test_line.y_;
  }
}

void YasApplication::Run() {
  TimePicker timePicker = TimePicker();
  time_ = timePicker.getSeconds();
  fps_time_ = 0.0F;
  frames_ = 0;

  while (!quit_) {
    while (SDL_PollEvent(&event_)) {
      HandleInput();
    }

    new_time_ = timePicker.getSeconds();
    delta_time_ = new_time_ - time_;
    time_ = new_time_;

    ++frames_;
    fps_time_ = fps_time_ + delta_time_;
    if (fps_time_ >= 1.0F) {
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
  SDL_DestroyRenderer(sdl_renderer_);
  SDL_DestroyWindow(window_);
  SDL_Quit();
}


