#include <Windows.h>
#include"ArgumentParser.h"
#include <iostream>
#include "ConInfoRegex.h"
#include "Globals.h"
void SetArgumentMonochrome(std::string arg)
{
  if (std::regex_match(arg, ConInfoRegex::MONOCHROME))
  {
    monochrome = true;
  }
}
void SetArgumentUnformatted(std::string arg)
{
  if (std::regex_match(arg, ConInfoRegex::UNFORMATTED))
  {
    monochrome = true;
    unformatted = true;
  }
}
void SetBufferColumnsRows(std::string arg)
{
  if (std::regex_match(arg, ConInfoRegex::BUFFER))
  {
    if (!(hasIndivualSwitchesBeenEnabled))
    {
      hasIndivualSwitchesBeenEnabled = true;
      buffercolumns = false;
      bufferrows = false;
      cursorcolumn = false;
      cursorrow = false;
    }
    columns = true;
    rows = true;
  }
}
void SetColumnsRows(std::string arg)
{
  if (std::regex_match(arg, ConInfoRegex::SIZE))
  {
    if (!(hasIndivualSwitchesBeenEnabled))
    {
      hasIndivualSwitchesBeenEnabled = true;
      buffercolumns = false;
      bufferrows = false;
      cursorcolumn = false;
      cursorrow = false;
    }
    columns = true;
    rows = true;
  }
}
void SetCursorColumnRow(std::string arg)
{
  if (std::regex_match(arg, ConInfoRegex::CURSOR))
  {
    if (!(hasIndivualSwitchesBeenEnabled))
    {
      hasIndivualSwitchesBeenEnabled = true;
      columns = false;
      rows = false;
      buffercolumns = false;
      bufferrows = false;
    }
    cursorcolumn = true;
    cursorrow = true;
  }
}
void SetBufferColumns(std::string arg)
{
  if (std::regex_match(arg, ConInfoRegex::BUFFERCOLUMNS))
  {
    if (!(hasIndivualSwitchesBeenEnabled))
    {
      hasIndivualSwitchesBeenEnabled = true;
      columns = false;
      rows = false;
      bufferrows = false;
      cursorcolumn = false;
      cursorrow = false;
    }
    buffercolumns = true;
  }
}
void SetBufferRows(std::string arg)
{
  if (std::regex_match(arg, ConInfoRegex::BUFFERROWS))
  {
    if (!(hasIndivualSwitchesBeenEnabled))
    {
      hasIndivualSwitchesBeenEnabled = true;
      columns = false;
      rows = false;
      buffercolumns = false;
      cursorcolumn = false;
      cursorrow = false;
    }
    bufferrows = true;
  }
}
void SetColumns(std::string arg)
{
  if (std::regex_match(arg, ConInfoRegex::COLUMNS))
  {
    if (!(hasIndivualSwitchesBeenEnabled))
    {
      hasIndivualSwitchesBeenEnabled = true;
      rows = false;
      buffercolumns = false;
      bufferrows = false;
      cursorcolumn = false;
      cursorrow = false;
    }
    columns = true;
  }
}
void SetRows(std::string arg)
{
  if (std::regex_match(arg, ConInfoRegex::ROWS))
  {
    if (!(hasIndivualSwitchesBeenEnabled))
    {
      hasIndivualSwitchesBeenEnabled = true;
      columns = false;
      buffercolumns = false;
      bufferrows = false;
      cursorcolumn = false;
      cursorrow = false;
    }
    rows = true;
  }
}
void SetCursorColumn(std::string arg)
{
  if (std::regex_match(arg, ConInfoRegex::CURSORCOLUMN))
  {
    if (!(hasIndivualSwitchesBeenEnabled))
    {
      hasIndivualSwitchesBeenEnabled = true;
      columns = false;
      rows = false;
      buffercolumns = false;
      bufferrows = false;
      cursorrow = false;
    }
    cursorcolumn = true;
  }
}
void SetCursorRow(std::string arg)
{
  if (std::regex_match(arg, ConInfoRegex::CURSORROW))
  {
    if (!(hasIndivualSwitchesBeenEnabled))
    {
      hasIndivualSwitchesBeenEnabled = true;
      columns = false;
      rows = false;
      buffercolumns = false;
      bufferrows = false;
      cursorcolumn = false;
    }
    cursorrow = true;
  }
}

Arguments::Arguments(int argc, const char** argv, int start, char switch_char)
{
  const std::vector<std::string> argv_list(argv + start, argv + argc);
  for (int index = 0; index < (int)argv_list.size(); index++)
  {
    if (argv_list[index][0] == switch_char)
    {
      ARGLIST.push_back(argv_list[index].substr(1));
    }
  }
}
std::vector<std::string> Arguments::GetArgumentList()
{
  return ARGLIST;
}

void Arguments::ParseArguments()
{
  std::vector<std::string> argList = GetArgumentList();
  if ((int)argList.size() > 0)
  {
    for (std::string arg : argList)
    {
      if (std::regex_match(arg, ConInfoRegex::HELP))
      {
        const std::string HELPMESSAGE =
          "\n"
          "Con Info - Get a console's column and row size, cursor position, and buffer\n"
          "           size. Defaults to all information.\n"
          "\n"
          "confinfo [/? | /h | /help] | [/b | /buffer] [/s | /size] [/C | /cursor]\n"
          "         [/c | /columns] [/r | /rows] [/bc | /buffercolumns]\n"
          "         [/br | /bufferrows] [/cc | /cursorcolumn] [/cr | /cursorrow]\n"
          "         [/u | /unformatted]\n"
          "\n"
          "  /?, /h, /help        This help screen.\n"
          "  /b, /buffer          Only print the buffer size by columns and rows.\n"
          "  /s, /size            Only print the visible console's size by columns and\n"
          "                       rows.\n"
          "  /C, /cursor          Only print the cursor position by column and row.\n"
          "  /c, /columns         Only print the visible console's column width.\n"
          "  /r, /rows            Only print the visible console's column height.\n"
          "  /bc, /buffercolumns  Only print the buffer's width.\n"
          "  /br, /bufferrows     Only print the buffer's height.\n"
          "  /cc, /cursorcolumn   Only print the cursors's column position (X).\n"
          "  /cr, /cursorrow      Only print the cursors's row position (Y).\n"
          "  /u, /unformatted     No special formatting; no color and only returns\n"
          "                       integer values. Values are printed in their normal\n"
          "                       formatted order. Implies /monochrome.\n"
          "  /m, /monochrome      No color output.\n"
          "\n";
        std::cout << HELPMESSAGE << std::endl;
        WaitCheck();
        return std::exit(EXIT_SUCCESS);
      }
      SetArgumentMonochrome(arg);
      SetArgumentUnformatted(arg);
      SetBufferColumnsRows(arg);
      SetColumnsRows(arg);
      SetCursorColumnRow(arg);
      SetBufferColumns(arg);
      SetBufferRows(arg);
      SetColumns(arg);
      SetRows(arg);
      SetCursorColumn(arg);
      SetCursorRow(arg);
    }
  }
}