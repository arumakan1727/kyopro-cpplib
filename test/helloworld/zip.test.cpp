#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <cassert>
#include <iostream>
#include <vector>
#include <string>

#include "../../Util/zip.hpp"

int main() {
    using namespace std;
    std::cout << "Hello World" << std::endl;

    vector<int> a{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<char> c{'a', 'b', 'c', 'd'};
    vector<string> s{"zero", "one", "two"};

    const vector<pair<int, char>> excpect1 = {
        {0, 'a'}, {1, 'b'}, {2, 'c'}, {3, 'd'}
    };

    const vector<tuple<int, char, string>> excpect2 = {
        {0, 'a', "zero"}, {1, 'b', "one"}, {2, 'c', "two"}
    };

    assert(zip(a, c) == excpect1);
    assert(zip(a, c, s) == excpect2);

    return 0;
}
