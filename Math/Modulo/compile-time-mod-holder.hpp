#pragma once
#include "../../Util/int-alias.hpp"

/**
 * @brief Compile-Time-Mod-Holder (コンパイル時modを保持する型)
 *
 * ModInt のテンプレートパラメータに渡して使う。
 */
template <i64 Mod>
struct CompileTimeModHolder {
    static constexpr i64 mod = Mod;
};
