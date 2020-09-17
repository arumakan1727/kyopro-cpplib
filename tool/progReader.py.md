---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "def linesBelowDoc(progPath: str) -> list:\n    with open(progPath, 'r') as\
    \ f:\n        lines = f.readlines()\n\n    docBegin = '/**'\n    docLast = '*/'\n\
    \n    docBeginFound = False\n    docLastIndex = -1\n\n    for i, line in enumerate(lines):\n\
    \        if docBegin in line:\n            docBeginFound = True\n        elif\
    \ (docBeginFound is True) and (docLast in line):\n            docLastIndex = i\n\
    \            break\n\n    if docLastIndex == -1:\n        raise Exception(progPath\
    \ + \": Doc comment not found\")\n    else:\n        return lines[docLastIndex\
    \ + 1:]\n\n\ndef allLines(progPath: str) -> list:\n    with open(progPath, 'r')\
    \ as f:\n        lines = f.readlines()\n    return lines\n"
  dependsOn: []
  isVerificationFile: false
  path: tool/progReader.py
  requiredBy: []
  timestamp: '2020-09-17 11:52:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tool/progReader.py
layout: document
redirect_from:
- /library/tool/progReader.py
- /library/tool/progReader.py.html
title: tool/progReader.py
---
