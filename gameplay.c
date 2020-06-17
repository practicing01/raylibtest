#include "raylib.h"
#include "gameLoop.h"
#include "linux_platform.h"

void GameplayLoop(struct DeltaTime *dt)
{
	BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawText("GameplayLoop", 190, 200, 20, LIGHTGRAY);
	EndDrawing();
}
