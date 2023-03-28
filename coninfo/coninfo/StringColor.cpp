#include "StringColor.h"
StringColor::StringColor()
{
  intensity = "\x1b[1m";
  green = "\x1b[32m";
  lightgreen = "\x1b[92m";
  yellow = "\x1b[33m";
  lightyellow = "\x1b[93m";
  cyan = "\x1b[36m";
  lightcyan = "\x1b[96m";
  lightblue = "\x1b[94m";
  reset = "\x1b[m";
}
void StringColor::NullColors()
{
  intensity = "";
  green = "";
  lightgreen = "";
  yellow = "";
  lightyellow = "";
  cyan = "";
  lightcyan = "";
  lightblue = "";
  reset = "";
}
std::string StringColor::Intensity()
{
  return intensity;
}
std::string StringColor::Green()
{
  return green;
}
std::string StringColor::LightGreen()
{
  return lightgreen;
}
std::string StringColor::Yellow()
{
  return yellow;
}
std::string StringColor::LightYellow()
{
  return lightyellow;
}
std::string StringColor::Cyan()
{
  return cyan;
}
std::string StringColor::LightCyan()
{
  return lightcyan;
}
std::string StringColor::LightBlue()
{
  return lightblue;
}
std::string StringColor::Reset()
{
  return reset;
}