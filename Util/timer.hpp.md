---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Timer (\u5B9F\u884C\u6642\u9593\u8A08\u6E2C)"
    links: []
  bundledCode: "#line 2 \"Util/timer.hpp\"\n#include <chrono>\n\n/**\n * @brief Timer\
    \ (\u5B9F\u884C\u6642\u9593\u8A08\u6E2C)\n */\nclass Timer {\n    std::chrono::system_clock::time_point\
    \ m_start;\n\npublic:\n    Timer() = default;\n\n    inline void start() {\n \
    \       m_start = std::chrono::system_clock::now();\n    }\n\n    inline uint64_t\
    \ elapsedMilli() const {\n        using namespace std::chrono;\n        const\
    \ auto end = system_clock::now();\n        return duration_cast<milliseconds>(end\
    \ - m_start).count();\n    }\n};\n"
  code: "#pragma once\n#include <chrono>\n\n/**\n * @brief Timer (\u5B9F\u884C\u6642\
    \u9593\u8A08\u6E2C)\n */\nclass Timer {\n    std::chrono::system_clock::time_point\
    \ m_start;\n\npublic:\n    Timer() = default;\n\n    inline void start() {\n \
    \       m_start = std::chrono::system_clock::now();\n    }\n\n    inline uint64_t\
    \ elapsedMilli() const {\n        using namespace std::chrono;\n        const\
    \ auto end = system_clock::now();\n        return duration_cast<milliseconds>(end\
    \ - m_start).count();\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Util/timer.hpp
  requiredBy: []
  timestamp: '2020-10-10 05:23:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Util/timer.hpp
layout: document
redirect_from:
- /library/Util/timer.hpp
- /library/Util/timer.hpp.html
title: "Timer (\u5B9F\u884C\u6642\u9593\u8A08\u6E2C)"
---
