#pragma once
#include "../template-parts/type-alias.hpp"

/**
 * @brief Compiletime Mod Holder (コンパイル時modを保持する型)
 *
 * ModInt のテンプレートパラメータに渡して使う。
 */
template <i64 Mod>
struct CompiletimeModHolder {
    static constexpr i64 mod = Mod;
};
