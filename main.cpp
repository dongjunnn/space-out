#include <raylib.h>
#include "entity/ship.h"
#include "entity/config.h"

int main() {
    InitWindow(800, 800, "Space-Out");
    SetTargetFPS(constants::fps);

    auto ship = Ship();

    while (!WindowShouldClose()) {    
        if (IsKeyDown(KEY_LEFT)) {
            ship.acc_anticlockwise();
        }
        if (IsKeyDown(KEY_UP)) {
            ship.acc();
        }
        if (IsKeyDown(KEY_RIGHT)) {
            ship.acc_clockwise();
        }
        // drawing the game objects to screen
        auto [pos_x, pos_y, angle] = ship.simulate();
        BeginDrawing();
        ClearBackground(BLACK);
        auto vertices = gen_triangle_vertices(pos_x, pos_y, angle, 20.f);
        DrawTriangle(vertices[0], vertices[1], vertices[2], WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
