import os
import os.path as path
import sys
import progReader
import glob

rootDir = path.join(os.path.dirname(__file__), "../")
longSnippetsFileGlob = path.join(rootDir, "[A-Z]*/**/*.hpp")
shortSnippetsFileGlob = path.join(rootDir, "short-snip/*.[ch]pp")


def genSnippet(srcFiles, useAllLines, addFoldMarker):
    srcFiles.sort()

    for fpath in srcFiles:
        baseName = path.basename(fpath)
        dirBaseName = path.basename(path.dirname(fpath))
        base_ext_pair = path.splitext(baseName)

        if useAllLines:
            lines = progReader.allLines(fpath)
        else:
            lines = progReader.linesBelowDoc(fpath)

        snipTrigger = base_ext_pair[0]
        snipDescription = path.join(dirBaseName, baseName)
        snipBody = "".join(lines)

        if snipBody[-1] != '\n':
            snipBody += '\n'

        sys.stdout.write('snippet {} "{}"\n'.format(
            snipTrigger, snipDescription))

        if addFoldMarker:
            sys.stdout.write("// " + base_ext_pair[0] + " {{{\n")
            sys.stdout.write(snipBody)
            sys.stdout.write("// }}}\n")
        else:
            sys.stdout.write(snipBody)

        sys.stdout.write("endsnippet\n\n")

    pass


if __name__ == '__main__':
    if len(sys.argv) != 2:
        sys.stderr.write("Error: Please ONE option.\n")
        sys.exit(1)

    elif sys.argv[1] == '--short-snippets':
        genSnippet(glob.glob(shortSnippetsFileGlob), True, False)

    elif sys.argv[1] == '--long-snippets':
        genSnippet(glob.glob(longSnippetsFileGlob, recursive=True), False, True)

    else:
        sys.stderr.writelines([
            "Error: Unknown option.\n",
            "Available option:\n",
            "    --short-snippets\n",
            "    --long-snippets\n",
        ])
        sys.exit(1)
