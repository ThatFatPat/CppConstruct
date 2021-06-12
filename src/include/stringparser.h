#pragma once

#include <cstddef>
#include <string>

#include "integralparser.h"
#include "parser.h"

template <typename Char, size_t N>
class BasicStringParser {
 public:
  using parsing_type = std::basic_string<Char>;

  static parsing_type parse(IReadable& stream, ParsingContext& context) {
    auto arr =
        parseWithHooks<ArrayParser<IntegralParser<Char>, N>>(stream, context);
    parsing_type ret(arr.cbegin(), arr.cend());

    // Resize to the maximum size of the padded string data.
    ret.resize(std::strlen(ret.data()));

    return ret;
  }
};

template <size_t N>
using StringParser = BasicStringParser<char, N>;

template <size_t N>
using WstringParser = BasicStringParser<wchar_t, N>;