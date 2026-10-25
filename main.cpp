#include <raylib.h>
#include <format>
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
        if (IsKeyDown(KEY_LEFT_SHIFT)) {
            ship.boost();
        }
        // drawing the game objects to screen
        auto [pos_x, pos_y, angle] = ship.simulate();
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText(TextFormat("Boost: %.2f", ship.get_boost_store()), 0, 760, 25, GREEN);
        DrawPoly({ pos_x, pos_y }, 3, 20, angle * RAD2DEG, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
