#pragma once
#include <type_traits>
#include "raylib.h"
#include "../compiler.h"

float projectPoint(Vector2 axis, Vector2 point) {
    return axis.x * point.x + axis.y * point.y;
}

namespace collision_detector {
    FORCE_INLINE bool detect_collision(const auto& v1, const auto& v2) {
        static_assert(std::is_same_v<decltype(v1), decltype(v2)>, "Input types to collision_detector must match");
        if (v1.size() < 3 || v2.size() < 3) return false;

        for (int shape = 0; shape < 2; ++shape) {
            const auto& vertices = (shape == 0) ? v1 : v2;

            for (std::size_t i = 0; i < vertices.size(); ++i) {
                const Vector2& a = vertices[i];
                const Vector2& b = vertices[(i + 1) % vertices.size()];

                Vector2 axis = {-(b.y - a.y), b.x - a.x};
                if (axis.x == 0.0f && axis.y == 0.0f) continue;

                float min1 = projectPoint(axis, v1[0]);
                float max1 = min1;
                float min2 = projectPoint(axis, v2[0]);
                float max2 = min2;

                for (const Vector2& point : v1) {
                    float s = projectPoint(axis, point);
                    if (s < min1) min1 = s;
                    if (s > max1) max1 = s;

                }

                for (const Vector2& point : v2) {
                    float s = projectPoint(axis, point);
                    if (s < min2) min2 = s;
                    if (s > max2) max2 = s;
                }

                if (max1 < min2 || max2 < min1) return false;
            }
        }

        return true;
    }
}
