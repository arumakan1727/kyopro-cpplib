#pragma once
#include <chrono>

/**
 * @brief Timer (実行時間計測)
 */
class Timer {
    std::chrono::system_clock::time_point m_start;

public:
    Timer() = default;

    inline void start() {
        m_start = std::chrono::system_clock::now();
    }

    inline uint64_t elapsedMilli() const {
        using namespace std::chrono;
        const auto end = system_clock::now();
        return duration_cast<milliseconds>(end - m_start).count();
    }
};
