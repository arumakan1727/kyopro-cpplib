#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <bits/stdc++.h>

#include "../../Util/runlength.hpp"

using namespace std;

void test1() {
    array<int, 6> a{1, 1, 5, 5, 5, -8};

    const vector<pair<decltype(a)::iterator, size_t>> expected = {
        {begin(a) + 0, size_t(2)},
        {begin(a) + 2, size_t(3)},
        {begin(a) + 5, size_t(1)},
    };

    assert(runlength(begin(a), end(a)) == expected);
    clog << __func__ << " : OK" << endl;
}

void test2() {
    array<int, 1> a{1727};

    const vector<pair<decltype(a)::iterator, size_t>> expected = {
        {begin(a) + 0, size_t(1)},
    };

    assert(runlength(begin(a), end(a)) == expected);
    clog << __func__ << " : OK" << endl;
}

void test3() {
    string s = "x01ssss";

    const vector<pair<decltype(s)::iterator, size_t>> expected = {
        {begin(s) + 0, size_t(1)},
        {begin(s) + 1, size_t(1)},
        {begin(s) + 2, size_t(1)},
        {begin(s) + 3, size_t(4)},
    };

    assert(runlength(begin(s), end(s)) == expected);
    clog << __func__ << " : OK" << endl;
}

int main() {
    std::cout << "Hello World" << std::endl;

    test1();
    test2();
    test3();

    return 0;
}
