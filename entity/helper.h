#pragma once

#include <random>

template <typename T>
T random_num(T lower_bound, T upper_bound) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<T> dist(lower_bound, upper_bound);
    return dist(gen);
}

