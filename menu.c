#include "raylib.h"
#include "gameLoop.h"
#include "linux_platform.h"

void MenuLoop(struct DeltaTime *dt)
{
	BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawText("MenuLoop", 190, 200, 20, LIGHTGRAY);
	EndDrawing();
}
