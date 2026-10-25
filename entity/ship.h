#pragma once
#include "type.h"
#include "helper.h"
#include <cmath>
#include <numbers>

class Ship {
    static constexpr float jerk{600.f};
    static constexpr float max_acc{300.f};
    static constexpr float spool_down{1200.f};
    static constexpr float max_speed{350.f};
    static constexpr float drag{0.8f};
    static constexpr float turn_rate{3.5f};

    static constexpr float boost_incr{1000.f};
    static constexpr float boost_acc_incr{150.f};
    static constexpr float max_boost_store{100.f};    
    static constexpr float boost_use_rate{25.0};
    static constexpr float boost_regen_rate{10.f}; 

private:
    float pos_x, pos_y;
    float angle{std::numbers::pi};
    vec2d speed{0, 0};
    float speed_acc{0};
    bool thrusting{false};
    bool boosting{false};
    float boost_store{100.f};

public:
    Ship();
    void acc(); 
    void acc_clockwise();
    void acc_anticlockwise();
    void boost(); 
    
    float get_boost_store();
    entity_info simulate();
    ~Ship() = default;
};
