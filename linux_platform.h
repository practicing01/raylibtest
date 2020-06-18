#ifndef LINUX_PLATFORM_H
#define LINUX_PLATFORM_H

#include "raylib.h"

enum ModulePhase {SPLASH, MENU, GAMEPLAY};

void SetModule(enum ModulePhase);

#endif
