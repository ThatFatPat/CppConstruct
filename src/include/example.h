#pragma once

#include <string>

#include "integralparser.h"
#include "stringparser.h"
#include "structparser.h"

struct A {
  int x;
  int y;
  bool a;
  std::string str;
};

using AParser =
    StructParser<A, IntParser, IntParser, BoolParser<int>, StringParser<10>>;