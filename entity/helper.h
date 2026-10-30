#pragma once
#include <array>
#include <cmath>
#include <random>
#include "raylib.h"

template <typename T>
T random_num(T lower_bound, T upper_bound) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<T> dist(lower_bound, upper_bound);
    return dist(gen);
}

struct vec2d {
    float x;
    float y;

    float magnitude() {
        return std::sqrt(x * x + y * y);
    }
};

inline std::array<Vector2, 3>  gen_triangle_vertices(float pos_x, float pos_y, float angle, float distance_from_centre) {
    float a = angle;
    float b = angle - 2.f * PI / 3.f;
    float c = angle - 4.f * PI / 3.f;

    return {{
        {pos_x + distance_from_centre * std::cos(a),
         pos_y + distance_from_centre * std::sin(a)},
        {pos_x + distance_from_centre * std::cos(b),
         pos_y + distance_from_centre * std::sin(b)},
        {pos_x + distance_from_centre * std::cos(c),
         pos_y + distance_from_centre * std::sin(c)}
    }};
}
