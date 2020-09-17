def linesBelowDoc(progPath: str) -> list:
    with open(progPath, 'r') as f:
        lines = f.readlines()

    docBegin = '/**'
    docLast = '*/'

    docBeginFound = False
    docLastIndex = -1

    for i, line in enumerate(lines):
        if docBegin in line:
            docBeginFound = True
        elif (docBeginFound is True) and (docLast in line):
            docLastIndex = i
            break

    if docLastIndex == -1:
        raise Exception(progPath + ": Doc comment not found")
    else:
        return lines[docLastIndex + 1:]


def allLines(progPath: str) -> list:
    with open(progPath, 'r') as f:
        lines = f.readlines()
    return lines
