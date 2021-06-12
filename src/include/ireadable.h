#pragma once
#include <cstddef>
#include <span>

class IReadable {
 public:
  virtual void read(std::span<std::byte> buffer) = 0;
};