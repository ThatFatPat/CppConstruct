#pragma once
#include <span>

#include "ireadable.h"
#include "parsingcontext.h"

// template <typename T>
// class Parser {
//  public:
//   using parsing_type = T;

//   static parsing_type parse(IReadable &stream, ParsingContext &context);
// };

template <typename Parser>
typename Parser::parsing_type parseWithHooks(IReadable &stream,
                                             ParsingContext &context) {
  return Parser::parse(stream, context);
}

void readWithHooks(IReadable &stream, std::span<std::byte> buffer,
                   ParsingContext &context);
