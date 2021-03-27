---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/0558-Cheese.test.cpp
    title: test/AOJ/0558-Cheese.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "fillContainer() (\u30B3\u30F3\u30C6\u30CA\u306Efill)"
    links: []
  bundledCode: "#line 2 \"Util/fillContainer.hpp\"\n#include <cstdint>\n#include <type_traits>\n\
    #include <functional>\n\n/**\n * @brief fillContainer() (\u30B3\u30F3\u30C6\u30CA\
    \u306Efill)\n */\ntemplate <class T, class Container, class... ConstructorArgs,\
    \ std::enable_if_t<std::is_same<Container, T>::value, std::nullptr_t> = nullptr>\n\
    inline void fillContainer(Container& container, ConstructorArgs&&... constructorArgs)\
    \ {\n    container = T(std::forward<ConstructorArgs>(constructorArgs)...);\n}\n\
    \ntemplate <class T, class Container, class... ConstructorArgs, std::enable_if_t<!std::is_same<Container,\
    \ T>::value, std::nullptr_t> = nullptr>\ninline void fillContainer(Container&\
    \ container, ConstructorArgs&&... constructorArgs) {\n    for (auto& e: container)\
    \ fillContainer<T>(e, std::forward<ConstructorArgs>(constructorArgs)...);\n}\n"
  code: "#pragma once\n#include <cstdint>\n#include <type_traits>\n#include <functional>\n\
    \n/**\n * @brief fillContainer() (\u30B3\u30F3\u30C6\u30CA\u306Efill)\n */\ntemplate\
    \ <class T, class Container, class... ConstructorArgs, std::enable_if_t<std::is_same<Container,\
    \ T>::value, std::nullptr_t> = nullptr>\ninline void fillContainer(Container&\
    \ container, ConstructorArgs&&... constructorArgs) {\n    container = T(std::forward<ConstructorArgs>(constructorArgs)...);\n\
    }\n\ntemplate <class T, class Container, class... ConstructorArgs, std::enable_if_t<!std::is_same<Container,\
    \ T>::value, std::nullptr_t> = nullptr>\ninline void fillContainer(Container&\
    \ container, ConstructorArgs&&... constructorArgs) {\n    for (auto& e: container)\
    \ fillContainer<T>(e, std::forward<ConstructorArgs>(constructorArgs)...);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Util/fillContainer.hpp
  requiredBy: []
  timestamp: '2020-09-25 22:04:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/0558-Cheese.test.cpp
documentation_of: Util/fillContainer.hpp
layout: document
redirect_from:
- /library/Util/fillContainer.hpp
- /library/Util/fillContainer.hpp.html
title: "fillContainer() (\u30B3\u30F3\u30C6\u30CA\u306Efill)"
---
