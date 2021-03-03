#include "raylib.h"
#include "rlgl.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#undef RAYGUI_IMPLEMENTATION

int main() {
	InitWindow(800, 450, "raylib - rotation cube");
	SetTargetFPS(60);

	Camera3D camera = {0};
	camera.position = (Vector3) {10, 6.5, 10};
	camera.target = (Vector3) {0.0f, 1.5f, 5.0f};
	camera.up = (Vector3) {0.0f, 1.0f, 0.0f};
	camera.fovy = 45.0f;
	camera.type = CAMERA_PERSPECTIVE;

	float cubeSpeed = 5;
	Vector3 cubePosition = {0,1.5,0};
	auto cubeColor = DARKPURPLE;

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);

		BeginMode3D(camera);
		rlPushMatrix();
		rlRotatef(GetTime()*cubeSpeed*20,0,1,0);
		DrawCube(cubePosition,3,3,3,cubeColor);
		DrawCubeWires(cubePosition,3,3,3,DARKGREEN);
		DrawGrid(10,10);
		rlPopMatrix();
		EndMode3D();

		/* GUI  */
		GuiPanel((Rectangle){0,0,400,450});
		DrawText("Cube speed",120,10,30,LIGHTGRAY);
		cubeSpeed = GuiSlider((Rectangle){20,50,360,30}, nullptr, nullptr,cubeSpeed,0,10);
		DrawText("Cube color",120,150,30,LIGHTGRAY);
		cubeColor = GuiColorPicker((Rectangle){100,200,200,200},cubeColor);

		EndDrawing();
	}
	CloseWindow();
	return 0;
}
