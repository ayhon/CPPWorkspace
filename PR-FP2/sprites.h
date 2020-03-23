#ifndef _SPRITES_H
#define _SPRITES_H

// Diferencias entre windows y linux. (MacOS como que no, sorry)
#ifdef _WIN32
const bool OS_WIN = true;
#include <conio.h>
#elif __linux__
const bool OS_WIN = false;
#include <curses.h>
#endif

#include <iostream>
#include <vector>
#include "mina.h"
void sprite(tElemento elem, int section);
void printTitleScreen();
void colorFondo(int color, string msg, vector<int> extra);

#endif