#include "lib.hpp"

auto main() -> int
{
  auto const lib = library {};

  return lib.name == "cmake_init" ? 0 : 1;
}
