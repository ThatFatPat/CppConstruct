#include <iostream>

#include "include/arrayparser.h"
#include "include/bufferreadable.h"
#include "include/integralparser.h"
#include "include/structparser.h"

int main() {
  constexpr char message[] = "\x01\x00\x00\x00\x02\x00\x00\x00\x03\x00\x00\x00";
  BufferReadable br(std::span{reinterpret_cast<const std::byte*>(message),
                              std::size(message)});
  ParsingContext ctx;
  auto [a, b] =
      parseWithHooks<StructParser<IntParser, ArrayParser<IntParser, 2>>>(br,
                                                                         ctx);
  std::cout << a << std::endl;
  std::cout << b[0] << std::endl;
  std::cout << b[1] << std::endl;
}