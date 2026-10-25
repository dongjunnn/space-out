#include "ship.h"
#include "config.h"
#include "helper.h"
#include <algorithm>
#include <cmath>

Ship::Ship() : pos_x(static_cast<float>(random_num(0, constants::world_x_size))), pos_y(static_cast<float>(random_num(0, constants::world_y_size))) {}

void Ship::acc() {
    thrusting = true; 
}

void Ship::acc_clockwise() {
    angle += turn_rate * constants::dt;
}

void Ship::acc_anticlockwise() {
    angle -= turn_rate * constants::dt;
}

entity_info Ship::simulate() {
    if (thrusting) {
        speed_acc = std::min(max_acc, speed_acc + jerk * constants::dt);
    } else {
        speed_acc = std::max(0.f, speed_acc - spool_down * constants::dt);
    }
    thrusting = false;

    if (speed.magnitude() < max_speed) {                                // enforcing max speed
        speed.x += speed_acc * std::cos(angle) * constants::dt;         
        speed.y += speed_acc * std::sin(angle) * constants::dt;
    }
    
    speed.x *= std::exp(-drag * constants::dt);                         // speed decay
    speed.y *= std::exp(-drag * constants::dt);   

    pos_x += speed.x * constants::dt;
    pos_y += speed.y * constants::dt;

    return {pos_x, pos_y, angle};
}
