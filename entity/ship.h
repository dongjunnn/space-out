#pragma once
#include "type.h"
#include "helper.h"
#include <cmath>
#include <numbers>

class Ship {
private:
    static constexpr float jerk{600.f};
    static constexpr float max_acc{300.f};
    static constexpr float spool_down{1200.f};
    static constexpr float max_speed{350.f};
    static constexpr float drag{0.8f};
    static constexpr float turn_rate{3.5f};

    float pos_x, pos_y;
    float angle{std::numbers::pi};
    vec2d speed{0, 0};
    float speed_acc{0};
    bool thrusting{false};

public:
    static constexpr float dist_from_centre{20.f};

    Ship();
    void acc();
    void acc_clockwise();
    void acc_anticlockwise();
    void simulate();
    std::array<Vector2, 3> gen_vertice();
    entity_info update();
    ~Ship() = default;
};
