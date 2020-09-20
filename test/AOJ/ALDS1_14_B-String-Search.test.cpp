#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include <iostream>
#include <string>
#include <vector>

#include "../../String/rolling-hash.hpp"
#include "../../String/rabin-karp.hpp"
#include "../../Util/IO/println.hpp"
#include "../../Util/all-macro.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    using RH = RollingHash<17273747>;

    std::string T, P;
    std::cin >> T >> P;

    const RH rolHashT(all(T));
    const RH rolHashP(all(P));

    for (const auto foundIndex : rabinKarp(rolHashT, rolHashP)) {
        println(foundIndex);
    }

    return 0;
}
