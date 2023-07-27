#!/usr/bin/env python3
import asyncio
import sys
from pathlib import Path
from typing import NamedTuple

import aiofiles


def print_usage() -> None:
    print(f"Usage: {sys.argv[0]} [-h] [CPP_FILE]...")


class LintErr(NamedTuple):
    linenr: int
    msg: str


class LintResult(NamedTuple):
    path: Path
    errs: list[LintErr]


async def lint(filepath: Path) -> LintResult:
    async with aiofiles.open(filepath, "rt") as f:
        line = (await f.readline()).strip()
        if filepath.suffix in (".h", ".hpp") and line != "#pragma once":
            return LintResult(
                filepath, [LintErr(1, "Missing `#pragma once` at first line.")]
            )

        i = 1
        async for line in f:
            line = line.strip()
            i += 1

            if "using namespace std;" in line:
                return LintResult(
                    filepath, [LintErr(i, "Do not use `using namespace std`.")]
                )

    return LintResult(filepath, [])


async def run(paths: list[Path]):
    results: list[LintResult] = await asyncio.gather(*(lint(path) for path in paths))
    results.sort(key=lambda x: x.path)

    num_err_file = 0
    for r in results:
        if len(r.errs) == 0:
            continue

        num_err_file += 1
        for err in r.errs:
            print(f"[ERR] {r.path}:{err.linenr}: {err.msg}")

    if num_err_file == 0:
        print(f"[OK] No errors found ✨ (checked {len(results)} files)")
        exit(0)
    else:
        print("-----")
        print(f"{num_err_file} errors found 🔥 (checked {len(results)} files)")
        exit(1)


def main(args: list[str]) -> None:
    if ("-h" in args) or ("--help" in args):
        print_usage()
        exit()

    paths = [Path(a) for a in args if not a.startswith("-")]
    asyncio.run(run(paths))


if __name__ == "__main__":
    main(sys.argv[1:])
