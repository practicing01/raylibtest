#ifndef MODULELOOP_H
#define MODULELOOP_H

#include "raylib.h"

struct DeltaTime
{
	float deltaTime;
	float elapsedTime;
};

struct DeltaTime dt;
struct Vector2 defaultRes;

void *moduleData;
void (*ModuleLoop)(void);

void ScaleVec2(struct Vector2 *result, struct Vector2 *point, struct Vector2 *oldRes, struct Vector2 *newRes);

#endif
