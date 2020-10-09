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
  code: "import os\nimport os.path as path\nimport sys\nimport progReader\nimport\
    \ glob\n\nrootDir = path.join(os.path.dirname(__file__), \"../\")\nlongSnippetsFileGlob\
    \ = path.join(rootDir, \"[A-Z]*/**/*.hpp\")\nshortSnippetsFileGlob = path.join(rootDir,\
    \ \"short-snip/*.[ch]pp\")\n\n\ndef genSnippet(srcFiles, useAllLines, addFoldMarker):\n\
    \    srcFiles.sort()\n\n    for fpath in srcFiles:\n        baseName = path.basename(fpath)\n\
    \        dirBaseName = path.basename(path.dirname(fpath))\n        base_ext_pair\
    \ = path.splitext(baseName)\n\n        if useAllLines:\n            lines = progReader.allLines(fpath)\n\
    \        else:\n            lines = progReader.linesBelowDoc(fpath)\n\n      \
    \  snipTrigger = base_ext_pair[0]\n        snipDescription = path.join(dirBaseName,\
    \ baseName)\n        snipBody = \"\".join(lines)\n\n        if snipBody[-1] !=\
    \ '\\n':\n            snipBody += '\\n'\n\n        sys.stdout.write('snippet {}\
    \ \"{}\"\\n'.format(\n            snipTrigger, snipDescription))\n\n        if\
    \ addFoldMarker:\n            sys.stdout.write(\"// \" + base_ext_pair[0] + \"\
    \ {{{\\n\")\n            sys.stdout.write(snipBody)\n            sys.stdout.write(\"\
    // }}}\\n\")\n        else:\n            sys.stdout.write(snipBody)\n\n      \
    \  sys.stdout.write(\"endsnippet\\n\\n\")\n\n    pass\n\n\nif __name__ == '__main__':\n\
    \    if len(sys.argv) != 2:\n        sys.stderr.write(\"Error: Please ONE option.\\\
    n\")\n        sys.exit(1)\n\n    elif sys.argv[1] == '--short-snippets':\n   \
    \     genSnippet(glob.glob(shortSnippetsFileGlob), True, False)\n\n    elif sys.argv[1]\
    \ == '--long-snippets':\n        genSnippet(glob.glob(longSnippetsFileGlob, recursive=True),\
    \ False, True)\n\n    else:\n        sys.stderr.writelines([\n            \"Error:\
    \ Unknown option.\\n\",\n            \"Available option:\\n\",\n            \"\
    \    --short-snippets\\n\",\n            \"    --long-snippets\\n\",\n       \
    \ ])\n        sys.exit(1)\n"
  dependsOn: []
  isVerificationFile: false
  path: tool/gen-snippet.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tool/gen-snippet.py
layout: document
redirect_from:
- /library/tool/gen-snippet.py
- /library/tool/gen-snippet.py.html
title: tool/gen-snippet.py
---
