#pragma once
#include <cstddef>

#include "arrayparser.h"
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
using ByteParser = IntegralParser<std::byte>;

template <size_t N>
using BytesParser = ArrayParser<ByteParser, N>;

template <typename I>
class BoolParser {
 public:
  using parsing_type = bool;

  static parsing_type parse(IReadable& stream, ParsingContext& context) {
    return IntegralParser<I>::parse(stream, context) != 0;
  }
};