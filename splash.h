#ifndef SPLASH_H
#define SPLASH_H

#include "raylib.h"
#include "moduleLoop.h"
#include "linux_platform.h"

struct SplashData
{
	Texture2D tex;
};

void SplashInit();
void SplashExit();
void SplashLoop();

#endif
