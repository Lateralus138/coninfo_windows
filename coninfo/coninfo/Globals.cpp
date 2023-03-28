#include "Globals.h"
#include <iostream>
bool monochrome = false;
bool unformatted = false;
bool columns = true;
bool rows = true;
bool buffercolumns = true;
bool bufferrows = true;
bool cursorcolumn = true;
bool cursorrow = true;
bool hasIndivualSwitchesBeenEnabled = false;
void WaitCheck()
{
	const bool ISOWNWINDOW = []()
	{
		DWORD processList[2] = { 0 };
		const DWORD maxList = 2;
		DWORD result = GetConsoleProcessList((LPDWORD)processList, maxList);
		return (result == 1);
	}();
	if (ISOWNWINDOW)
	{
		std::cout << "Press [\x1b[1;3;93mEnter\x1b[m] to continue... > ";
		std::cin.ignore();
	}
}
void SetConInfoStringStreamBuffer(std::stringstream& stream, StringColor& color, CONSOLE_SCREEN_BUFFER_INFO consoleOutputInfo)
{
  if (buffercolumns)
  {
    stream
      << color.Intensity() << color.Green() << ((!(unformatted)) ? "Buffer Columns" : "") << color.Reset()
      << ((!(unformatted)) ? " : [" : "") << color.Intensity() << color.LightGreen()
      << consoleOutputInfo.dwSize.X << color.Reset() << ((!(unformatted)) ? "]" : "") << '\n';
  }
  if (bufferrows)
  {
    stream
      << color.Intensity() << color.Green() << ((!(unformatted)) ? "Buffer Rows" : "") << color.Reset()
      << ((!(unformatted)) ? "    : [" : "") << color.Intensity() << color.LightGreen()
      << consoleOutputInfo.dwSize.Y << color.Reset() << ((!(unformatted)) ? "]" : "") << '\n';
  }
}
void SetConInfoStringStreamCursor(std::stringstream& stream, StringColor color, CONSOLE_SCREEN_BUFFER_INFO consoleOutputInfo)
{
  if (cursorcolumn)
  {
    stream
      << color.Intensity() << color.Yellow() << ((!(unformatted)) ? "Cursor Column" : "") << color.Reset()
      << ((!(unformatted)) ? "  : [" : "") << color.Intensity() << color.LightYellow()
      << consoleOutputInfo.dwCursorPosition.X << color.Reset() << ((!(unformatted)) ? "]" : "") << '\n';
  }
  if (cursorrow)
  {
    stream
      << color.Intensity() << color.Yellow() << ((!(unformatted)) ? "Cursor Row" : "") << color.Reset()
      << ((!(unformatted)) ? "     : [" : "") << color.Intensity() << color.LightYellow()
      << consoleOutputInfo.dwCursorPosition.Y << color.Reset() << ((!(unformatted)) ? "]" : "") << '\n';
  }
}
void SetConInfoStringStreamSize(std::stringstream& stream, StringColor color, CONSOLE_SCREEN_BUFFER_INFO consoleOutputInfo)
{
  if (columns)
  {
    stream
      << color.Intensity() << color.Cyan() << ((!(unformatted)) ? "Columns" : "") << color.Reset()
      << ((!(unformatted)) ? "        : [" : "") << color.Intensity() << color.LightCyan()
      << consoleOutputInfo.dwMaximumWindowSize.X << color.Reset() << ((!(unformatted)) ? "]" : "") << '\n';
  }
  if (rows)
  {
    stream
      << color.Intensity() << color.Cyan() << ((!(unformatted)) ? "Rows" : "") << color.Reset()
      << ((!(unformatted)) ? "           : [" : "") << color.Intensity() << color.LightCyan()
      << consoleOutputInfo.dwMaximumWindowSize.Y << color.Reset() << ((!(unformatted)) ? "]" : "") << '\n';
  }
}