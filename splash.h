#ifndef SPLASH_H
#define SPLASH_H

#include "raylib.h"
#include "moduleLoop.h"
#include "linux_platform.h"

struct SplashData
{
	Model logo;
	Texture2D tex;
	Camera camera;
	Vector3 logoPos;
	char splashPhase;
	char maxPhases;
	Music logoMusic;
};

void SplashPhase();
void SplashInit();
void SplashExit();
void SplashLoop();

#endif
