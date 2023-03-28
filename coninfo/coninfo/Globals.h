#pragma once
#ifndef GLOBALS_H
#define GLOBALS_H
#include "StringColor.h"
#include <sstream>
#include <Windows.h>
extern bool monochrome;
extern bool unformatted;
extern bool columns;
extern bool rows;
extern bool buffercolumns;
extern bool bufferrows;
extern bool cursorcolumn;
extern bool cursorrow;
extern bool hasIndivualSwitchesBeenEnabled;
void WaitCheck();
void SetConInfoStringStreamBuffer(std::stringstream& stream, StringColor& color, CONSOLE_SCREEN_BUFFER_INFO consoleOutputInfo);
void SetConInfoStringStreamCursor(std::stringstream& stream, StringColor color, CONSOLE_SCREEN_BUFFER_INFO consoleOutputInfo);
void SetConInfoStringStreamSize(std::stringstream& stream, StringColor color, CONSOLE_SCREEN_BUFFER_INFO consoleOutputInfo);
#endif // !GLOBALS_H

