#include "raylib.h"
#include "raymath.h"

int main() {
	InitWindow(800, 450, "raylib - rotation cube");
	SetTargetFPS(60);

	Camera3D camera = {0};
	float camera_pos = 5.0f;
	camera.position = (Vector3) {camera_pos, camera_pos, camera_pos};
	camera.target = (Vector3) {0.0f, 0.0f, 0.0f};
	camera.up = (Vector3) {0.0f, 1.0f, 0.0f};
	camera.fovy = 45.0f;
	camera.type = CAMERA_PERSPECTIVE;

	/* bottom points */
	Vector3 bottom_a = {-0.5, 0, -0.5};
	Vector3 bottom_b = {-0.5, 0, 0.5};
	Vector3 bottom_c = {0.5, 0, -0.5};
	Vector3 bottom_d = {0.5, 0, 0.5};

	/* top points */
	Vector3 top_a = {-0.5, 1, -0.5};
	Vector3 top_b = {-0.5, 1, 0.5};
	Vector3 top_c = {0.5, 1, -0.5};
	Vector3 top_d = {0.5, 1, 0.5};

	Matrix myMatrix = MatrixRotateY(0.08f);

	while (!WindowShouldClose()) {
		/* rotating the points */
		bottom_a = Vector3Transform(bottom_a, myMatrix);
		bottom_b = Vector3Transform(bottom_b, myMatrix);
		bottom_c = Vector3Transform(bottom_c, myMatrix);
		bottom_d = Vector3Transform(bottom_d, myMatrix);

		top_a = Vector3Transform(top_a, myMatrix);
		top_b = Vector3Transform(top_b, myMatrix);
		top_c = Vector3Transform(top_c, myMatrix);
		top_d = Vector3Transform(top_d, myMatrix);

		BeginDrawing();
		ClearBackground(RAYWHITE);
		BeginMode3D(camera);

		/* Creating the meshes */

		DrawTriangle3D(bottom_a, bottom_b, top_a, RED);
		DrawTriangle3D(top_a, bottom_b, top_b, RED);

		DrawTriangle3D(bottom_b, bottom_d, top_b, GREEN);
		DrawTriangle3D(top_b, bottom_d, top_d, GREEN);

		DrawTriangle3D(bottom_d, bottom_c, top_d, BLUE);
		DrawTriangle3D(top_d, bottom_c, top_c, BLUE);

		DrawTriangle3D(bottom_c, bottom_a, top_c, ORANGE);
		DrawTriangle3D(top_c, bottom_a, top_a, ORANGE);

		DrawTriangle3D(top_a, top_b, top_c, PURPLE);
		DrawTriangle3D(top_c, top_b, top_d, PURPLE);

		EndMode3D();
		EndDrawing();
	}
	CloseWindow();
	return 0;
}