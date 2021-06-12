#include "parser.h"

void readWithHooks(IReadable &stream, std::span<std::byte> buffer,
                   ParsingContext &context) {
  return stream.read(buffer);
}