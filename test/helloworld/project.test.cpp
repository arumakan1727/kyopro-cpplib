#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <bits/stdc++.h>

#include "../../Util/project.hpp"

using namespace std;

void test1() {
    vector<pair<int, char>> a {
        {0, 'a'},
        {1, 'b'},
        {2, 'c'},
    };

    const vector<int> expected0 = {0, 1, 2};
    const vector<char> expected1 = {'a', 'b', 'c'};

    assert(project<0>(a) == expected0);
    assert(project<1>(a) == expected1);

    clog << __func__ << " : OK" << endl;
}

void test2() {
    vector<tuple<int, char, bool>> a {
        {0, 'a', true},
        {1, 'b', false},
        {2, 'c', true},
    };

    const vector<int> expected0 = {0, 1, 2};
    const vector<char> expected1 = {'a', 'b', 'c'};
    const vector<bool> expected2 = {true, false, true};

    assert(project<0>(a) == expected0);
    assert(project<1>(a) == expected1);
    assert(project<2>(a) == expected2);

    clog << __func__ << " : OK" << endl;
}

int main() {
    std::cout << "Hello World" << std::endl;

    test1();
    test2();

    return 0;
}
