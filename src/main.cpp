#include <iostream>

#include "arrayparser.h"
#include "bufferreadable.h"
#include "example.h"
#include "integralparser.h"
#include "structparser.h"

int main() {
  constexpr char message[] =
      "\x01\x00\x00\x00\x02\x00\x00\x00\x03\x00\x00\x00helloworld";
  BufferReadable br(std::span{reinterpret_cast<const std::byte*>(message),
                              std::size(message)});
  ParsingContext ctx;
  auto a = parseWithHooks<AParser>(br, ctx);
  std::cout << a.x << std::endl;
  std::cout << a.y << std::endl;
  std::cout << a.a << std::endl;
  std::cout << a.str << std::endl;
}