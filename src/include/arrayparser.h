#pragma once

#include <algorithm>
#include <array>

#include "parser.h"

template <typename ParserType, size_t N>
class ArrayParser {
 public:
  using parsing_type = std::array<typename ParserType::parsing_type, N>;

  static parsing_type parse(IReadable& stream, ParsingContext& context) {
    parsing_type ret;
    for (auto& v : ret) {
      // Keep array index in context.
      v = parseWithHooks<ParserType>(stream, context);
    }
    return ret;
  }
};