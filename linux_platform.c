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
#include "gameLoop.h"
#include "splash.h"
#include "menu.h"
#include "gameplay.h"

void SetLoop(enum LoopPhase lp, struct DeltaTime *dt)
{
	dt->elapsedTime = 0.0f;
	
	if (lp == MENU)
	{
		GameLoop = MenuLoop;
	}
	else if (lp == GAMEPLAY)
	{
		GameLoop = GameplayLoop;
	}
	else if (lp == SPLASH)
	{
		GameLoop = SplashLoop;
	}
}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    
    struct DeltaTime dt;
    dt.elapsedTime = 0.0f;
    
    enum LoopPhase phase = SPLASH;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(30);               // Set our game to run at 30 frames-per-second
    //--------------------------------------------------------------------------------------

	GameLoop = SplashLoop;
	
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
		dt.deltaTime = GetFrameTime();
		
        // Draw
        //----------------------------------------------------------------------------------
        GameLoop(&dt);
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
