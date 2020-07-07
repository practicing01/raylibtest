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
	
	struct Vector2 scaledDims;
	struct Vector2 dims;
	dims.x = 100;
	dims.y = 100;
	struct Vector2 curRes;
	curRes.x = GetScreenWidth();
	curRes.y = GetScreenHeight();
	
	ScaleVec2(&scaledDims, &dims, &defaultRes, &curRes);
	
	(*data).playButt.x = (screenWidth/2) - scaledDims.x;
	(*data).playButt.y = (screenHeight/2) - scaledDims.y;
	(*data).playButt.width = scaledDims.x;
	(*data).playButt.height = scaledDims.y;
	
	(*data).defautFontSize = 20;
	int defaultArea = defaultRes.x * defaultRes.y;
	int curArea = curRes.x * curRes.y;
	(*data).curFontSize = ( curArea * (*data).defautFontSize ) / defaultArea;
	
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
				DrawText("Play Pressed!", 0, 0, (* (struct MenuData *)moduleData).curFontSize, LIGHTGRAY);
			};
		}
		else
		{
			DrawRectangleLines( (* (struct MenuData *)moduleData).playButt.x, (* (struct MenuData *)moduleData).playButt.y,
			(* (struct MenuData *)moduleData).playButt.width, (* (struct MenuData *)moduleData).playButt.height, DARKGRAY);
		}
		
		DrawText("Play", (* (struct MenuData *)moduleData).playButt.x, (* (struct MenuData *)moduleData).playButt.y, (* (struct MenuData *)moduleData).curFontSize, MAROON);
		
	EndDrawing();
}
