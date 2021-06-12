#pragma once
#include <cstddef>
#include <span>

#include "ireadable.h"

class BufferReadable : public IReadable {
 public:
  BufferReadable(std::span<const std::byte> span)
      : m_span(span), m_ptr(span.begin()) {}
  void read(std::span<std::byte> buffer) override;

 private:
  std::span<const std::byte> m_span;
  std::span<const std::byte>::iterator m_ptr;
};