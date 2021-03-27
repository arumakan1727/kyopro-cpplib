---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "def linesBelowDoc(progPath: str) -> list:\n    with open(progPath, 'r') as\
    \ f:\n        lines = f.readlines()\n\n    DOC_BEGIN_MARKER = '/**'\n\n    for\
    \ i, line in enumerate(lines):\n        if DOC_BEGIN_MARKER in line:\n       \
    \     return lines[i:]\n\n    raise Exception(progPath + \": Doc comment not found\"\
    )\n\n\ndef allLines(progPath: str) -> list:\n    with open(progPath, 'r') as f:\n\
    \        lines = f.readlines()\n    return lines\n"
  dependsOn: []
  isVerificationFile: false
  path: tool/progReader.py
  requiredBy: []
  timestamp: '2020-10-25 20:18:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tool/progReader.py
layout: document
redirect_from:
- /library/tool/progReader.py
- /library/tool/progReader.py.html
title: tool/progReader.py
---
