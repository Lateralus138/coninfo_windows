#pragma once
#ifndef CONINFOREGEX_H
#define CONINFOREGEX_H
#include <regex>
namespace ConInfoRegex
{
  const std::regex HELP = std::regex("^([\?]|[hH]|[hH][eE][lL][pP])$");
  const std::regex BUFFER = std::regex("^([bB]|[bB][uU][fF][fF][eE][rR])$");
  const std::regex SIZE = std::regex("^([sS]|[sS][iI][zZ][eE])$");
  const std::regex CURSOR = std::regex("^([C]|[cC][uU][rR][sS][oO][rR])$");
  const std::regex COLUMNS = std::regex("^([c]|[cC][oO][lL][uU][mM][nN][sS])$");
  const std::regex ROWS = std::regex("^([rR]|[rR][oO][wW][sS])$");
  const std::regex BUFFERCOLUMNS = std::regex("^([bB][cC]|[bB][uU][fF][fF][eE][rR][cC][oO][lL][uU][mM][nN][sS])$");
  const std::regex BUFFERROWS = std::regex("^([bB][rR]|[bB][uU][fF][fF][eE][rR][rR][oO][wW][sS])$");
  const std::regex CURSORCOLUMN = std::regex("^([cC][cC]|[cC][uU][rR][sS][oO][rR][cC][oO][lL][uU][mM][nN])$");
  const std::regex CURSORROW = std::regex("^([cC][rR]|[cC][uU][rR][sS][oO][rR][rR][oO][wW])$");
  const std::regex UNFORMATTED = std::regex("^([uU]|[uU][nN][fF][oO][rR][mM][aA][tT][tT][eE][dD])$");
  const std::regex MONOCHROME = std::regex("^([mM]|[mM][oO][nN][oO][cC][hH][rR][oO][mM][eE])$");
};
#endif // !CONINFOREGEX_H
