#!/usr/bin/env bash
set -euo pipefail

if [[ $# -lt 1 ]]; then
  echo >&2 "[INFO] No source files are given. Bye!"
  exit
fi

args=("$@")

trap cleanup SIGINT SIGTERM ERR EXIT

tmpfile="$(mktemp --suffix=-clangformat)"

cleanup() {
    trap - SIGINT SIGTERM ERR EXIT
    rm -f "$tmpfile"
}

cnt_total_files=0
cnt_formatted=0

for file in "${args[@]}" ; do
  _=$((cnt_total_files++))

  clang-format "$file" > "$tmpfile"

  if ! diff -q "$file" "$tmpfile" &>/dev/null ; then
    cp "$tmpfile" "$file"
    _=$((cnt_formatted++))
    echo "Formatted $file"
  fi
done

if [[ $cnt_formatted -eq 0 ]]; then
  echo "[OK] All files are already formatted ✨ (Checked $cnt_total_files files)"
else
  echo "[OK] $cnt_formatted files were formatted ✨ (Checked $cnt_total_files files)"
fi
