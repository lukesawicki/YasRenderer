//
// Created by lukesawicki on 9/29/24.
//

#ifndef LINE_3D_HPP
#define LINE_3D_HPP
#include <SDL2/SDL_stdinc.h>

#include "vector_3d.hpp"
#include "vector_4d.hpp"

// Line defined as pair of indekses in vertices table
class Line3D {
  public:
  Vector4D<Uint8> color_;
  int v1_;
  int v2_;
};

#endif //LINE_3D_HPP
