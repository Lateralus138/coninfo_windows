//////////////////////////////////////////////////////////////
// Con Info                                                 //
// Get a console's column and row size, cursor position,    //
// and buffer size.                                         //
// © 2023 Ian Pride - New Pride Software / Services         //
//////////////////////////////////////////////////////////////
#include <Windows.h>
#include <iostream>
#include <sstream>
#include "ArgumentParser.h"
#include "StringColor.h"
#include "Globals.h"
int main(int argc, const char* argv[])
{
  Arguments Args(argc, argv, 1, '/');
  StringColor color;
  HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
  SetConsoleMode(hInput, ENABLE_VIRTUAL_TERMINAL_INPUT);
  HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleMode(hOutput, ENABLE_PROCESSED_OUTPUT | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleTitle(L"Con Info");
  CONSOLE_SCREEN_BUFFER_INFO consoleOutputInfo;
  const int hasConsoleOutputinfo = GetConsoleScreenBufferInfo(hOutput, &consoleOutputInfo);
  if (argc > 1)
  {
    Args.ParseArguments();
  }
  if (monochrome)
  {
    color.NullColors();
  }
  if (hasConsoleOutputinfo > 0)
  {
    std::stringstream stream;
    if (!(unformatted))
    {
      stream << '\n';
      stream
        << color.Intensity() << color.LightBlue() << "Console Information" << color.Reset() << "\n\n";
    }
    SetConInfoStringStreamBuffer(stream, color, consoleOutputInfo);
    SetConInfoStringStreamCursor(stream, color, consoleOutputInfo);
    SetConInfoStringStreamSize(stream, color, consoleOutputInfo);
    if (!(unformatted))
    {
      stream << '\n';
    }
    const std::string MESSAGE = stream.str();
    stream.clear();
    std::cout << MESSAGE;
  }
  else
  {
    std::cerr
      << (monochrome ? "" : "\x1b[1;91m")
      << "Could not get the console's information."
      << (monochrome ? "" : "\x1b[m\n");
    WaitCheck();
    return EXIT_FAILURE;
  }
  WaitCheck();
  return EXIT_SUCCESS;
}