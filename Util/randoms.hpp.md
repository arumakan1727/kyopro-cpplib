---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/rolling-hash.test.cpp
    title: test/unittest/rolling-hash.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "randoms (randint()\u3068\u304Bchoice()\u3068\u304B)"
    links: []
  bundledCode: "#line 2 \"Util/randoms.hpp\"\n\n#include <random>\n#include <functional>\n\
    \n/**\n * @brief randoms (randint()\u3068\u304Bchoice()\u3068\u304B)\n */\nnamespace\
    \ arumakan::random {\n\nstd::mt19937 mt(std::random_device{}());\n\n// \u9589\u533A\
    \u9593[min, max] \u306E\u4E71\u6570\u3092\u4E00\u69D8\u5206\u5E03\u3067\u751F\u6210\
    \u3059\u308B\ntemplate <class Integer>\nInteger randint(Integer min, Integer max)\
    \ {\n    return std::uniform_int_distribution<Integer>(min, max)(mt);\n}\n\n//\
    \ dest \u306B randint(sizeMin, sizeMax) \u56DE randint(valueMin, valueMax) \u3092\
    \u683C\u7D0D\u3059\u308B\ntemplate <class OutputIter, class Integer>\nOutputIter\
    \ randomValueContainer(OutputIter dest, Integer valueMin, Integer valueMax, std::size_t\
    \ sizeMin, std::size_t sizeMax) {\n    auto size = randint(sizeMin, sizeMax);\n\
    \    while (size--) {\n        *dest = randint(valueMin, valueMax);\n        ++dest;\n\
    \    }\n    return dest;\n}\n\n// \u8981\u7D20\u6570\u304C randint(sizeMin, sizeMax)\
    \ \u306E randint(valueMin, valueMax) \u3092\u751F\u6210\u3059\u308B\ntemplate\
    \ <class Container, class Integer>\nContainer randomValueContainer(Integer valueMin,\
    \ Integer valueMax, std::size_t sizeMin, std::size_t sizeMax) {\n    Container\
    \ ret;\n    randomValueContainer(std::back_inserter(ret), valueMin, valueMax,\
    \ sizeMin, sizeMax);\n    return ret;\n}\n\n// [begin, end) \u306E\u7BC4\u56F2\
    \u306E\u3046\u3061\u3072\u3068\u3064\u3092\u30E9\u30F3\u30C0\u30E0\u306B\u9078\
    \u3093\u3067\u8FD4\u3059\ntemplate <class RandomAccessIter>\nauto choice(RandomAccessIter\
    \ begin, RandomAccessIter end) {\n    const auto i = randint<std::size_t>(0, std::distance(begin,\
    \ end));\n    return begin[i];\n}\n\n}  // namespace rand\n"
  code: "#pragma once\n\n#include <random>\n#include <functional>\n\n/**\n * @brief\
    \ randoms (randint()\u3068\u304Bchoice()\u3068\u304B)\n */\nnamespace arumakan::random\
    \ {\n\nstd::mt19937 mt(std::random_device{}());\n\n// \u9589\u533A\u9593[min,\
    \ max] \u306E\u4E71\u6570\u3092\u4E00\u69D8\u5206\u5E03\u3067\u751F\u6210\u3059\
    \u308B\ntemplate <class Integer>\nInteger randint(Integer min, Integer max) {\n\
    \    return std::uniform_int_distribution<Integer>(min, max)(mt);\n}\n\n// dest\
    \ \u306B randint(sizeMin, sizeMax) \u56DE randint(valueMin, valueMax) \u3092\u683C\
    \u7D0D\u3059\u308B\ntemplate <class OutputIter, class Integer>\nOutputIter randomValueContainer(OutputIter\
    \ dest, Integer valueMin, Integer valueMax, std::size_t sizeMin, std::size_t sizeMax)\
    \ {\n    auto size = randint(sizeMin, sizeMax);\n    while (size--) {\n      \
    \  *dest = randint(valueMin, valueMax);\n        ++dest;\n    }\n    return dest;\n\
    }\n\n// \u8981\u7D20\u6570\u304C randint(sizeMin, sizeMax) \u306E randint(valueMin,\
    \ valueMax) \u3092\u751F\u6210\u3059\u308B\ntemplate <class Container, class Integer>\n\
    Container randomValueContainer(Integer valueMin, Integer valueMax, std::size_t\
    \ sizeMin, std::size_t sizeMax) {\n    Container ret;\n    randomValueContainer(std::back_inserter(ret),\
    \ valueMin, valueMax, sizeMin, sizeMax);\n    return ret;\n}\n\n// [begin, end)\
    \ \u306E\u7BC4\u56F2\u306E\u3046\u3061\u3072\u3068\u3064\u3092\u30E9\u30F3\u30C0\
    \u30E0\u306B\u9078\u3093\u3067\u8FD4\u3059\ntemplate <class RandomAccessIter>\n\
    auto choice(RandomAccessIter begin, RandomAccessIter end) {\n    const auto i\
    \ = randint<std::size_t>(0, std::distance(begin, end));\n    return begin[i];\n\
    }\n\n}  // namespace rand\n"
  dependsOn: []
  isVerificationFile: false
  path: Util/randoms.hpp
  requiredBy: []
  timestamp: '2020-09-20 14:54:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/rolling-hash.test.cpp
documentation_of: Util/randoms.hpp
layout: document
redirect_from:
- /library/Util/randoms.hpp
- /library/Util/randoms.hpp.html
title: "randoms (randint()\u3068\u304Bchoice()\u3068\u304B)"
---
