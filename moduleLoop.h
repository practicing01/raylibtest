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

#endif
