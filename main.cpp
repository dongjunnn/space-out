#include <raylib.h>
#include "entity/ship.h"
#include "entity/config.h"
#include "collision_system/collision_detector.h"

int main() {
    InitWindow(800, 800, "Space-Out");
    SetTargetFPS(constants::fps);

    auto ship = Ship();
    auto ship_temp = Ship(); // for testing only: can delete

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

        ship.simulate();
        ship_temp.simulate();

        auto proposed_ship = ship;
        auto proposed_temp = ship_temp;

        proposed_ship.update();
        proposed_temp.update();

        auto proposed_vertices = proposed_ship.gen_vertice();
        auto proposed_temp_vertices = proposed_temp.gen_vertice();

        if (!collision_detector::detect_collision(
                proposed_vertices, proposed_temp_vertices)) {
            ship = proposed_ship;
            ship_temp = proposed_temp;
        }

        auto vertices = ship.gen_vertice();
        auto temp_vertices = ship_temp.gen_vertice();

        BeginDrawing();
        ClearBackground(BLACK);
        DrawTriangle(vertices[0], vertices[1], vertices[2], WHITE);
        DrawTriangle(temp_vertices[0], temp_vertices[1], temp_vertices[2], RED);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
