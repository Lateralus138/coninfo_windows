#pragma once
#ifndef STRINGCOLOR_H
#define STRINGCOLOR_H
#include <string>
class StringColor
{
private:
  std::string intensity;
  std::string green;
  std::string lightgreen;
  std::string yellow;
  std::string lightyellow;
  std::string cyan;
  std::string lightcyan;
  std::string lightblue;
  std::string reset;
public:
  StringColor();
  void NullColors();
  std::string Intensity();
  std::string Green();
  std::string LightGreen();
  std::string Yellow();
  std::string LightYellow();
  std::string Cyan();
  std::string LightCyan();
  std::string LightBlue();
  std::string Reset();
};
#endif // !STRINGCOLOR_H