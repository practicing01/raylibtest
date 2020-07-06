#ifndef MODULELOOP_H
#define MODULELOOP_H

struct DeltaTime
{
	float deltaTime;
	float elapsedTime;
};

struct DeltaTime dt;
void *moduleData;
void (*ModuleLoop)(void);

void ScaleVec2(struct Vector2 *result, struct Vector2 *point, struct Vector2 *oldScale, struct Vector2 *newScale);

#endif
