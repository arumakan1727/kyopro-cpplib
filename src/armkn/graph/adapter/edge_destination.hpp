#pragma once
#include <cstdint>
#include <type_traits>
#include <utility>

/// Adapter function for (Edge => DestNodeId) / (DestNodeId => DestNodeId)
struct EdgeDestinationAdapter {
  EdgeDestinationAdapter() = default;

  template <class T, std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>
  inline uint32_t operator()(T to) const noexcept {
    return static_cast<uint32_t>(to);
  }

  template <class T, class = std::void_t<decltype(std::declval<T>().to)> >
  inline uint32_t operator()(const T& edge) const noexcept {
    return static_cast<uint32_t>(edge.to);
  }
};
