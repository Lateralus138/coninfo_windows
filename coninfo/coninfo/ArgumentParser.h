#pragma once
#ifndef ARGUMENTPARSER_H
#define ARGUMENTPARSER_H
#include <vector>
#include <string>
class Arguments
{
private:
  std::vector<std::string> ARGLIST;
public:
  Arguments(int argc, const char ** argv, int start, char switch_char);
  std::vector<std::string> GetArgumentList();
  void ParseArguments();
};
#endif // !ARGUMENTPARSER_H
