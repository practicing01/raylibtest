#include "raylib.h"
#include "moduleLoop.h"
#include "linux_platform.h"
#include "gameplay.h"

void GameplayInit()
{
	dt.elapsedTime = 0.0f;
	ModuleLoop = GameplayLoop;
}

void GameplayExit()
{
	//
}

void GameplayLoop()
{
	BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawText("GameplayLoop", 190, 200, 20, LIGHTGRAY);
	EndDrawing();
	
	if (WindowShouldClose())
	{
		ExitGame();
	}
}
