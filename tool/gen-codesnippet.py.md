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
  code: "import os\nimport os.path as path\nimport sys\nimport progReader\nimport\
    \ glob\nfrom typing import List, Tuple\nimport json\n\nrootDir = path.join(os.path.dirname(__file__),\
    \ \"../\")\nlongSnippetsFileGlob = path.join(rootDir, \"[A-Z]*/**/*.hpp\")\nshortSnippetsFileGlob\
    \ = path.join(rootDir, \"short-snip/*.[ch]pp\")\n\n\ndef genSnippet(srcFiles:\
    \ List[str], useAllLines: bool) -> dict:\n    srcFiles.sort()\n\n    snippets\
    \ = dict()\n\n    for fpath in srcFiles:\n        baseName: str = path.basename(fpath)\n\
    \        dirBaseName: str = path.basename(path.dirname(fpath))\n        base_ext_pair:\
    \ Tuple[str, str] = path.splitext(baseName)\n\n        # lines = [\"#pragma region\"\
    ]\n        lines = []\n\n        if useAllLines:\n            lines.extend(l.rstrip()\
    \ for l in progReader.allLines(fpath))\n        else:\n            lines.extend(l.rstrip()\
    \ for l in progReader.linesBelowDoc(fpath))\n\n        snipTrigger = base_ext_pair[0]\n\
    \        snipDescription = \"(kyopro) \" +  path.join(dirBaseName, baseName)\n\
    \n        # lines.append(\"#pragma endregion\")\n\n        snip = {\n        \
    \    \"scope\": \"cpp\",\n            \"prefix\": snipTrigger,\n            \"\
    body\": lines,\n            \"description\": snipDescription,\n        }\n\n \
    \       snippets[snipDescription] = snip\n\n    return snippets\n\n\nif __name__\
    \ == '__main__':\n    shorSnippets = genSnippet(glob.glob(shortSnippetsFileGlob),\
    \ True)\n    longSnippets = genSnippet(glob.glob(longSnippetsFileGlob, recursive=True),\
    \ False)\n    allSnips = shorSnippets\n    allSnips.update(longSnippets)\n   \
    \ json.dump(allSnips, fp=sys.stdout, indent=2)\n"
  dependsOn: []
  isVerificationFile: false
  path: tool/gen-codesnippet.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tool/gen-codesnippet.py
layout: document
redirect_from:
- /library/tool/gen-codesnippet.py
- /library/tool/gen-codesnippet.py.html
title: tool/gen-codesnippet.py
---
