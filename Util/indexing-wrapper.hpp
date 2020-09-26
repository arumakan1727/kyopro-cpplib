#pragma once
#include <functional>

/**
 * @brief IndexingWrapper
 *
 * a.at(i [, j, k, ...]) をコンストラクタで受け取った関数オブジェクトの呼び出し indexConverter(i [, j, k, ...]) として呼び出す
 * indexConverter() は参照を返さなければならない
 */
template <class IndexConverterFunc>
struct IndexingWrapper {
    IndexConverterFunc indexConverter;

    IndexingWrapper(IndexConverterFunc indexConverter_)
        : indexConverter(indexConverter_) {}

    template <class... Args>
    auto&& at(Args&&... args) {
        return indexConverter(std::forward<Args>(args)...);
    }

    template <class... Args>
    const auto&& at(Args&&... args) const {
        return indexConverter(std::forward<Args>(args)...);
    }

    template <class Arg>
    auto&& operator[](Arg&& arg) {
        return indexConverter(std::forward<Arg>(arg));
    }

    template <class Arg>
    const auto&& operator[](Arg&& arg) const {
        return indexConverter(std::forward<Arg>(arg));
    }
};
