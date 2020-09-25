#pragma once
#include <functional>

/**
 * @brief FixPoint (ラムダ式の再帰)
 */
// Ex) FixPoint([&](auto func, int n) -> int {...})(10);
template <class F>
struct FixPoint : F {
    FixPoint(F&& f)
        : F(std::forward<F>(f)) {}

    template <class... Args>
    decltype(auto) operator()(Args&&... args) const {
        return F::operator()(*this, std::forward<Args>(args)...);
    }
};
