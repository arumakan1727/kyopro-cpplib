#pragma once
#define FN1(expr) ([&](auto const& _) { return (expr); })
#define FN2(expr) ([&](auto const& _1, auto const& _2) { return (expr); })
