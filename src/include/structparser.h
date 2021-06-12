#pragma once
#include <tuple>

#include "ireadable.h"
#include "parser.h"
#include "parsingcontext.h"

template <typename... Parsers>
using ParsingTypeTuple = std::tuple<typename Parsers::parsing_type...>;

template <typename... Parsers>
using ParserTypeTuple = std::tuple<Parsers...>;

template <typename S, typename... Parsers>
class StructParser {
 public:
  using parsing_type = S;
  // using parser_type = ParserTypeTuple<Parsers...>;

  static parsing_type parse(IReadable &stream, ParsingContext &context) {
    return parsing_type{parseWithHooks<Parsers>(stream, context)...};
  }
};
