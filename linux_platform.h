#ifndef LINUX_PLATFORM_H
#define LINUX_PLATFORM_H

#include "raylib.h"

enum LoopPhase {SPLASH, MENU, GAMEPLAY};

struct DeltaTime
{
	float deltaTime;
	float elapsedTime;
};

void SetLoop(enum LoopPhase, struct DeltaTime*);

#endif
