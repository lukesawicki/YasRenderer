//
// Created by lukesawicki on 10/12/24.
//

#ifndef TEST_BOX_3D_HPP
#define TEST_BOX_3D_HPP
#include "vector_2d.hpp"
#include "vector_4d.hpp"

class TestBox3D {
  public:
    Vector4D<float> position;
    Vector4D<float> v0;
    Vector4D<float> v1;
    Vector4D<float> v2;
    Vector4D<float> v3;
    Vector4D<float> v4;
    Vector4D<float> v5;
    Vector4D<float> v6;
    Vector4D<float> v7;
    Vector4D<float> *vertices;
    Vector4D<float> *worldVertices;
    Vector4D<float> *cameraVertices;
    Vector2D<float> *vertices_in_2d_;
    Vector4D<float> *resultVertices;

    TestBox3D() {
      vertices = new Vector4D<float>[8];
      vertices[0] = Vector4D<float>(-50, 50, 50, 1);
      vertices[1] = Vector4D<float>(-50, -50, 50, 1);
      vertices[2] = Vector4D<float>(50, -50, 50, 1);
      vertices[3] = Vector4D<float>(50, 50, 50, 1);
      vertices[4] = Vector4D<float>(50, 50, -50, 1);
      vertices[5] = Vector4D<float>(-50, -50, -50, 1);
      vertices[6] = Vector4D<float>(-50, -50, -50, 1);
      vertices[7] = Vector4D<float>(50, -50, -50, 1);

      worldVertices = new Vector4D<float>[8];
      for (int i = 0; i < 8; i++) {
        worldVertices[i].w_ = vertices[i].w_; // so 1
      }

      position = Vector4D<float>(175, 0, 0, 1);
    }
};

#endif //TEST_BOX_3D_HPP
