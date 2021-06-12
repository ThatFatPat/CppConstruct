#include "bufferreadable.h"

#include <memory>
#include <stdexcept>

void BufferReadable::read(std::span<std::byte> buffer) {
  if (m_span.end() - m_ptr < buffer.size()) {
    throw std::range_error("Buffer is too big!");
  }
  std::copy_n(m_ptr, buffer.size(), buffer.begin());
  m_ptr += buffer.size();
}
