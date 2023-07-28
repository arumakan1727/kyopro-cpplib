#pragma once
#include <cstdint>

template <typename T>
constexpr inline T infinity;

template <>
constexpr inline int32_t infinity<int32_t> = 0x3f3f3f3f;

template <>
constexpr inline uint32_t infinity<uint32_t> = 0x3f3f3f3f;

template <>
constexpr inline int64_t infinity<int64_t> = 0x3f3f3f3f3f3f3f3f;

template <>
constexpr inline uint64_t infinity<uint64_t> = 0x3f3f3f3f3f3f3f3f;
