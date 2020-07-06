#include "raylib.h"
#include "moduleLoop.h"
#include "linux_platform.h"
#include "menu.h"
#include <stdlib.h> 

void MenuInit()
{	
	dt.elapsedTime = 0.0f;
	
	struct MenuData *data = (struct MenuData *)malloc(sizeof(struct MenuData));
	
	int screenWidth = GetScreenWidth();
	int screenHeight = GetScreenHeight();
	
	(*data).playButt.x = (screenWidth/2) - 100;//todo: deal with scaling.
	(*data).playButt.y = (screenHeight/2) - 100;
	(*data).playButt.width = 100;
	(*data).playButt.height = 100;
	
	moduleData = data;
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
		
		DrawRectangleRec( (* (struct MenuData *)moduleData).playButt , LIGHTGRAY);
		if (CheckCollisionPointRec(GetMousePosition(), (* (struct MenuData *)moduleData).playButt) )
		{
			DrawRectangleLines( (* (struct MenuData *)moduleData).playButt.x, (* (struct MenuData *)moduleData).playButt.y,
			(* (struct MenuData *)moduleData).playButt.width, (* (struct MenuData *)moduleData).playButt.height, RED);
			
			if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
			{
				DrawText("Play Pressed!", 0, 0, 20, LIGHTGRAY);
			};
		}
		else
		{
			DrawRectangleLines( (* (struct MenuData *)moduleData).playButt.x, (* (struct MenuData *)moduleData).playButt.y,
			(* (struct MenuData *)moduleData).playButt.width, (* (struct MenuData *)moduleData).playButt.height, DARKGRAY);
		}
		
		DrawText("Play", (* (struct MenuData *)moduleData).playButt.x + 10, (* (struct MenuData *)moduleData).playButt.y + 10, 40, MAROON);
		
	EndDrawing();
}
