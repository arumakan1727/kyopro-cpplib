#pragma once

#include <random>
#include <functional>

/**
 * @brief randoms (randint()とかchoice()とか)
 */
namespace arumakan::random {

std::mt19937 mt(std::random_device{}());

// 閉区間[min, max] の乱数を一様分布で生成する
template <class Integer>
Integer randint(Integer min, Integer max) {
    return std::uniform_int_distribution<Integer>(min, max)(mt);
}

// dest に randint(sizeMin, sizeMax) 回 randint(valueMin, valueMax) を格納する
template <class OutputIter, class Integer>
OutputIter randomValueContainer(OutputIter dest, Integer valueMin, Integer valueMax, std::size_t sizeMin, std::size_t sizeMax) {
    auto size = randint(sizeMin, sizeMax);
    while (size--) {
        *dest = randint(valueMin, valueMax);
        ++dest;
    }
    return dest;
}

// 要素数が randint(sizeMin, sizeMax) の randint(valueMin, valueMax) を生成する
template <class Container, class Integer>
Container randomValueContainer(Integer valueMin, Integer valueMax, std::size_t sizeMin, std::size_t sizeMax) {
    Container ret;
    randomValueContainer(std::back_inserter(ret), valueMin, valueMax, sizeMin, sizeMax);
    return ret;
}

// [begin, end) の範囲のうちひとつをランダムに選んで返す
template <class RandomAccessIter>
auto choice(RandomAccessIter begin, RandomAccessIter end) {
    const auto i = randint<std::size_t>(0, std::distance(begin, end));
    return begin[i];
}

}  // namespace rand
