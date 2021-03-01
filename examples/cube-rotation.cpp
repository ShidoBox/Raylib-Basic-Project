#include "raylib.h"
#include "rlgl.h"

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

	while (!WindowShouldClose()) {

		BeginDrawing();
		ClearBackground(RAYWHITE);
		BeginMode3D(camera);

		rlPushMatrix();
		rlRotatef(GetTime()*45,0,1,0);
		DrawCube(Vector3Zero(),3,3,3,GREEN);
		DrawCubeWires(Vector3Zero(),3,3,3,DARKGREEN);
		DrawGrid(10,10);
		rlPopMatrix();

		EndMode3D();
		EndDrawing();
	}
	CloseWindow();
	return 0;
}