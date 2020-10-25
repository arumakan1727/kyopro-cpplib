def linesBelowDoc(progPath: str) -> list:
    with open(progPath, 'r') as f:
        lines = f.readlines()

    DOC_BEGIN_MARKER = '/**'

    for i, line in enumerate(lines):
        if DOC_BEGIN_MARKER in line:
            return lines[i:]

    raise Exception(progPath + ": Doc comment not found")


def allLines(progPath: str) -> list:
    with open(progPath, 'r') as f:
        lines = f.readlines()
    return lines
