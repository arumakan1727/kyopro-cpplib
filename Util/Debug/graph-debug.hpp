#pragma once
#include <iostream>
#include <iomanip>

#include "../../Graph/graph-template.hpp"
#include "./debug.hpp"

/**
 * @brief graph-debug (グラフのデバッグ出力)
 */
template <class T>
std::ostream& operator<<(std::ostream& os, const Edge<T>& e) {
    os << std::setw(0) << '(' << std::setfill('0') << std::setw(2) << e.from << "-" << std::setw(2) << e.to << ", w=" << std::setw(2) << e.weight;
    if (e.id != -1) os << ", id=" << std::setw(2) << e.id;
    os << std::setfill(' ') << ')';
    return os;
}

template<>
std::ostream& operator<<(std::ostream& os, const Edge<void>& e) {
    os << std::setw(0) << '(' << std::setfill('0') << std::setw(2) << e.from << "-" << std::setw(2) << e.to;
    if (e.id != -1) os << ", id=" << std::setw(2) << e.id;
    os << std::setfill(' ') << ')';
    return os;
}
