#include "ship.h"
#include "config.h"
#include "helper.h"
#include <algorithm>
#include <cmath>

Ship::Ship() : pos_x(random_num(0, constants::world_x_size)), pos_y(random_num(0, constants::world_y_size)) {}

void Ship::acc() {
    thrusting = true; 
}

void Ship::acc_clockwise() {
    angle += turn_rate * constants::dt;
}

void Ship::acc_anticlockwise() {
    angle -= turn_rate * constants::dt;
}

float Ship::get_boost_store() {
    return boost_store;
}

void Ship::boost() {
    if (boost_store >= 10) {
        boost_store -= boost_use_rate * constants::dt;

        boosting = true;
    }
    // implicitly else boosting is false
}

entity_info Ship::simulate() {
    if (thrusting) {
        speed_acc = std::min(max_acc + boosting * boost_incr, 
                             speed_acc + (jerk + (boost_acc_incr * boosting)) * constants::dt);
    } else {
        speed_acc = std::max(0.f, speed_acc - spool_down * constants::dt);
    }

    if (!boosting && boost_store < max_boost_store) { 
        boost_store += boost_regen_rate * constants::dt;
        boost_store = std::min(max_boost_store, boost_store);
    }

    thrusting = false;
    boosting = false;

    if (speed.magnitude() < max_speed + boosting * boost_incr) {        // enforcing max speed
        speed.x += speed_acc * std::cos(angle) * constants::dt;         
        speed.y += speed_acc * std::sin(angle) * constants::dt;
    }
    
    speed.x *= std::exp(-drag * constants::dt);                         // speed decay
    speed.y *= std::exp(-drag * constants::dt);   

    pos_x += speed.x * constants::dt;
    pos_y += speed.y * constants::dt;

    return {pos_x, pos_y, angle};
}
