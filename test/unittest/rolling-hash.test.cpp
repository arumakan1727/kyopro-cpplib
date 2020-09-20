#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <bits/stdc++.h>

#include "../../String/rolling-hash.hpp"

#include "../../Util/randoms.hpp"
#include "../../Util/all-macro.hpp"
#include "../../Util/rep-macro.hpp"
#include "../../Util/Debug/errln.hpp"

using namespace std;
namespace rnd = arumakan::random;
using RH = RollingHash<17273747>;

const auto testdatas = []() -> vector<pair<string, RH>> {
    string s1 = "a";
    string s2 = "zzzzz";
    string s3 = rnd::randomValueContainer<string>('a', 'b', 30, 50);
    string s4 = rnd::randomValueContainer<string>('x', 'z', 30, 50);

    return {
        {s1, RH(all(s1))},
        {s2, RH(all(s2))},
        {s3, RH(all(s3))},
        {s4, RH(all(s4))},
    };
}();

void test_hash() {
    for (const auto& [str, rolhash] : testdatas) {
        assert(rolhash.hash() == rolhash.rangeHash(0, str.length()));
    }

    errln("OK");
}

void test_rangeHash_and_substr() {
    for (const auto& [str, rolhash] : testdatas) {
        const auto N = str.length();
        rep(l1, 0, N) rep(r1, l1 + 1, N) {
            rep(l2, 0, N) rep(r2, l2 + 1, N) {
                const auto len1 = r1 - l1;
                const auto len2 = r2 - l2;

                const bool equality_expected = string_view(str).substr(l1, len1) == string_view(str).substr(l2, len2);
                const bool equality_rangeHash = rolhash.rangeHash(l1, r1) == rolhash.rangeHash(l2, r2);
                const bool equality_substr = rolhash.substr(l1, len1) == rolhash.substr(l2, len2);
                assert(equality_rangeHash == equality_expected);
                assert(equality_substr == equality_expected);
            }
        }
    }

    errln("OK");
}

void test_concat() {
    vector<int> a{1, 2, 3, 1, 2, 3};
    RH rolhash(all(a));

    const auto N = a.size();
    rep(l, 0, N) rep(m, l + 1, N) rep(r, m + 1, N) {
        const auto leftHash = rolhash.rangeHash(l, m);
        const auto rightHash = rolhash.rangeHash(m, r);
        const auto got = rolhash.concat(leftHash, rightHash, r - m);
        const auto expected = rolhash.rangeHash(l, r);
        assert(got == expected);
    }
    errln("OK");
}

int main() {
    std::cout << "Hello World" << std::endl;

    test_hash();
    test_rangeHash_and_substr();
    test_concat();

    return 0;
}
