#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <iostream>
#include <cassert>

#include "../../Util/fix-point.hpp"

void FixPoint_test() {
    const auto factorial = FixPoint([](auto f, int n) -> int {
        if (n <= 1) return 1;
        return n * f(n - 1);
    });

    assert(factorial(5) == 120);

    std::clog << __func__ << " : OK" << std::endl;
}

int main() {
    std::cout << "Hello World" << std::endl;

    FixPoint_test();

    return 0;
}
