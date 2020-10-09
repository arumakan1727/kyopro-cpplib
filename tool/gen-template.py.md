---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 85, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import os\nimport os.path as path\nimport re\nimport sys\nimport progReader\n\
    \nrootDir = path.join(os.path.dirname(__file__), \"../\")\ntemplatePrototypeFile\
    \ = path.join(rootDir, \"export/template-prototype.cpp\")\ntemplateFile = path.join(rootDir,\
    \ \"export/template.cpp\")\n\n\ndef genTemplate():\n    with open(templatePrototypeFile,\
    \ 'r') as f:\n        lines = f.readlines()\n\n    templatePrototypeDir = path.dirname(templatePrototypeFile)\n\
    \    userIncludeRegex = re.compile(r'^\\s*#\\s*include\\s+\"(.*)\"')\n\n    for\
    \ line in lines:\n        res = userIncludeRegex.match(line)\n        if res:\n\
    \            includeFile = path.join(templatePrototypeDir, res.group(1))\n   \
    \         includeContent = progReader.linesBelowDoc(includeFile)\n           \
    \ sys.stdout.write(\"\".join(includeContent))\n        else:\n            sys.stdout.write(line)\n\
    \n    pass\n\n\nif __name__ == '__main__':\n    genTemplate()\n"
  dependsOn: []
  isVerificationFile: false
  path: tool/gen-template.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tool/gen-template.py
layout: document
redirect_from:
- /library/tool/gen-template.py
- /library/tool/gen-template.py.html
title: tool/gen-template.py
---
