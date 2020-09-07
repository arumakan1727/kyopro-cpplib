#pragma once
#include "../template-parts/type-alias.hpp"

/**
 * @brief Runtime Mod Holder (実行時modを保持する型)
 *
 * ModInt のテンプレートパラメータに渡して使う。
 * 実行時に `RuntimeMod::mod` の値を書き換えることで ModInt の法を動的に設定できる。
 */
struct RuntimeModHolder {
    static i64 mod;
};
i64 RuntimeModHolder::mod;
