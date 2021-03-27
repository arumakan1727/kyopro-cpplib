import os
import os.path as path
import sys
import progReader
import glob
from typing import List, Tuple
import json

rootDir = path.join(os.path.dirname(__file__), "../")
longSnippetsFileGlob = path.join(rootDir, "[A-Z]*/**/*.hpp")
shortSnippetsFileGlob = path.join(rootDir, "short-snip/*.[ch]pp")


def genSnippet(srcFiles: List[str], useAllLines: bool) -> dict:
    srcFiles.sort()

    snippets = dict()

    for fpath in srcFiles:
        baseName: str = path.basename(fpath)
        dirBaseName: str = path.basename(path.dirname(fpath))
        base_ext_pair: Tuple[str, str] = path.splitext(baseName)

        # lines = ["#pragma region"]
        lines = []

        if useAllLines:
            lines.extend(l.rstrip() for l in progReader.allLines(fpath))
        else:
            lines.extend(l.rstrip() for l in progReader.linesBelowDoc(fpath))

        snipTrigger = base_ext_pair[0]
        snipDescription = "(kyopro) " +  path.join(dirBaseName, baseName)

        # lines.append("#pragma endregion")

        snip = {
            "scope": "cpp",
            "prefix": snipTrigger,
            "body": lines,
            "description": snipDescription,
        }

        snippets[snipDescription] = snip

    return snippets


if __name__ == '__main__':
    shorSnippets = genSnippet(glob.glob(shortSnippetsFileGlob), True)
    longSnippets = genSnippet(glob.glob(longSnippetsFileGlob, recursive=True), False)
    allSnips = shorSnippets
    allSnips.update(longSnippets)
    json.dump(allSnips, fp=sys.stdout, indent=2)
