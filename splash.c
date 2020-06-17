#include "raylib.h"
#include "gameLoop.h"
#include "linux_platform.h"

void SplashLoop(struct DeltaTime *dt)
{
	dt->elapsedTime += dt->deltaTime;
	
	BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawText(FormatText("SplashLoop delta: %f, %f", dt->deltaTime, dt->elapsedTime), 190, 200, 20, LIGHTGRAY);
	EndDrawing();
	
	if (dt->elapsedTime >= 5.0f)
	{
		SetLoop(MENU, dt);
	}
}
