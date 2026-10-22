#pragma once
#include "type.h"
#include <cmath>
#include <numbers>

class Ship {
    static constexpr float jerk{600.f};
    static constexpr float max_acc{300.f};
    static constexpr float spool_down{1200.f};
    static constexpr float max_speed{350.f};
    static constexpr float drag{0.8f};
    static constexpr float turn_rate{3.5f};

private:
    float pos_x, pos_y;
    float angle{std::numbers::pi};
    float speed{0};
    float speed_acc{0};
    bool thrusting{false};

public:
    Ship();
    void acc(); 
    void acc_clockwise();
    void acc_anticlockwise();
    entity_info simulate();
    ~Ship() = default;
};
