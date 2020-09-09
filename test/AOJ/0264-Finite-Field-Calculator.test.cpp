#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0264&lang=ja#"
#include <cassert>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>

#include "../../Math/Modulo/mod-int.hpp"

using namespace std;
using Mint = DynamicModInt<0>;
using Itr = string::const_iterator;

Mint expr(Itr&);
Mint term(Itr&);
Mint factor(Itr&);
Mint number(Itr&);

Mint expr(Itr& p) {
    Mint res = term(p);
    while (*p == '+' || *p == '-') {
        if (*p == '+') {
            res += term(++p);
        } else {
            res -= term(++p);
        }
    }
    return res;
}

Mint term(Itr& p) {
    Mint res = factor(p);
    while (*p == '*' || *p == '/') {
        if (*p == '*') {
            res *= factor(++p);
        } else {
            const auto v = factor(++p);
            if (v == 0) throw std::runtime_error("Divide by zero");
            res /= v;
        }
    }
    return res;
}

Mint factor(Itr& p) {
    if (*p == '(') {
        const auto res = expr(++p);
        assert(*p == ')');
        ++p;
        return res;
    }
    assert(isdigit(*p));
    return number(p);
}

Mint number(Itr& p) {
    int res = 0;
    while (isdigit(*p)) {
        res = res * 10 + (*p - '0');
        ++p;
    }
    return Mint::raw(res);
}

string removeSpace(const char* s) {
    string res;
    res.reserve(100010);

    istringstream iss(s);
    string part;
    while (iss >> part) res += move(part);

    return res;
}

int main() {
    static char line[100100];

    int p;
    while (scanf(" %d :", &p), p) {
        Mint::setMod(p);

        fgets(line, sizeof(line), stdin);
        const string s = removeSpace(line);

        try {
            Itr itr = s.cbegin();
            auto ans = expr(itr);
            printf("%s = %d (mod %ld)\n", s.c_str(), int(ans), Mint::mod());
        } catch (const std::runtime_error& e) {
            puts("NG");
        }
    }

    return 0;
}