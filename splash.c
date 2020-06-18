#include "raylib.h"
#include "moduleLoop.h"
#include "linux_platform.h"
#include "splash.h"
#include <stdlib.h> 

void SplashInit()
{
	dt.elapsedTime = 0.0f;
	
	struct SplashData *data = (struct SplashData *)malloc(sizeof(struct SplashData));
	
	data->tex = LoadTexture("splash/raylib_logo.png");
	
	moduleData = data;
	ModuleLoop = SplashLoop;
}

void SplashExit()
{
	UnloadTexture( ((struct SplashData *)moduleData)->tex );
	free( (struct SplashData *)moduleData );
	moduleData = NULL;
}

void SplashLoop()
{	
	int screenWidth = GetScreenWidth();
	int screenHeight = GetScreenHeight();
	int texWidth = ((struct SplashData *)moduleData)->tex.width;
	int texHeight = ((struct SplashData *)moduleData)->tex.height;
	
	BeginDrawing();
		ClearBackground(RAYWHITE);
		
		DrawTexture( ((struct SplashData *)moduleData)->tex , screenWidth/2 - texWidth/2, screenHeight/2 - texHeight/2, WHITE);
		
		DrawText(FormatText("SplashLoop delta: %f, %f", dt.deltaTime, dt.elapsedTime), 190, 200, 20, LIGHTGRAY);
	EndDrawing();
	
	if (dt.elapsedTime >= 5.0f)
	{
		SplashExit();
		SetModule(MENU);
	}
}
