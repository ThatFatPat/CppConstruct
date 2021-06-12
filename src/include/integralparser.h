#pragma once
#include <cstddef>

#include "parser.h"

template <typename I>
class IntegralParser {
 public:
  using parsing_type = I;

  static parsing_type parse(IReadable& stream, ParsingContext& context) {
    parsing_type res = 0;
    readWithHooks(stream,
                  {reinterpret_cast<std::byte*>(&res), sizeof(parsing_type)},
                  context);
    return res;
  }
};

using IntParser = IntegralParser<int>;