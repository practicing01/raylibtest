#ifndef MENU_H
#define MENU_H

#include "raylib.h"
#include "moduleLoop.h"
#include "linux_platform.h"

struct MenuData
{
	Rectangle playButt;
	Rectangle exitButt;
	int defautFontSize;
	int curFontSize;
};

void MenuInit();
void MenuExit();
void MenuLoop();

#endif
