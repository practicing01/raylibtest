/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples in Notepad++, provided with default raylib installer package, 
*   just press F6 and run [raylib_compile_execute] script, it will compile and execute.
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on [C:\raylib\raylib\examples] directory and
*   raylib official webpage: [www.raylib.com]
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2020 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "linux_platform.h"
#include "moduleLoop.h"
#include "splash.h"
#include "menu.h"
#include "gameplay.h"

void ScaleVec2(struct Vector2 *result, struct Vector2 *point, struct Vector2 *oldScale, struct Vector2 *newScale)
{
	int x = ( (*newScale).x * (*point).x ) / (*oldScale).x;
	int y = ( (*newScale).y * (*point).y ) / (*oldScale).y;
	
	(*result).x = x;
	(*result).y = y;
}

void SetModule(enum ModulePhase mp)
{
	if (mp == MENU)
	{
		MenuInit();
	}
	else if (mp == GAMEPLAY)
	{
		GameplayInit();
	}
	else if (mp == SPLASH)
	{
		SplashInit();
	}
}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    
    //enum ModulePhase phase = SPLASH;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(30);               // Set our game to run at 30 frames-per-second
    
    InitAudioDevice();
    //--------------------------------------------------------------------------------------
	
	SetModule(SPLASH);
	
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
		dt.deltaTime = GetFrameTime();
		dt.elapsedTime += dt.deltaTime;
		
        // Draw
        //----------------------------------------------------------------------------------
        ModuleLoop();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    
    CloseAudioDevice();
    
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
