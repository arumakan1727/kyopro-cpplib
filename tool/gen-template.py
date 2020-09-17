import os
import os.path as path
import re
import sys
import progReader

rootDir = path.join(os.path.dirname(__file__), "../")
templatePrototypeFile = path.join(rootDir, "export/template-prototype.cpp")
templateFile = path.join(rootDir, "export/template.cpp")


def genTemplate():
    with open(templatePrototypeFile, 'r') as f:
        lines = f.readlines()

    templatePrototypeDir = path.dirname(templatePrototypeFile)
    userIncludeRegex = re.compile(r'^\s*#\s*include\s+"(.*)"')

    for line in lines:
        res = userIncludeRegex.match(line)
        if res:
            includeFile = path.join(templatePrototypeDir, res.group(1))
            includeContent = progReader.linesBelowDoc(includeFile)
            sys.stdout.write("".join(includeContent))
        else:
            sys.stdout.write(line)

    pass


if __name__ == '__main__':
    genTemplate()
