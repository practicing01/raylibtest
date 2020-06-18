#include "raylib.h"
#include "moduleLoop.h"
#include "linux_platform.h"
#include "menu.h"

void MenuInit()
{
	dt.elapsedTime = 0.0f;
	ModuleLoop = MenuLoop;
}

void MenuExit()
{
	//
}

void MenuLoop()
{
	BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawText("MenuLoop", 190, 200, 20, LIGHTGRAY);
	EndDrawing();
}
