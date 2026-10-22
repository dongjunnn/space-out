#pragma once
#include <cmath>

namespace constants {
    constexpr int world_x_size = 800;
    constexpr int world_y_size = 800;
    constexpr int bullet_speed = 10;

    constexpr int fps = 120;
    constexpr float dt = 1.f / fps;

    inline float get_angle(float vel_x, float vel_y) {
        return std::atan2(vel_y, vel_x);
    }
}



