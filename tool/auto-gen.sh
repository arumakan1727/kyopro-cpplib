#!/usr/bin/env bash
set -eu

git config --local user.name "arumakan-git-remote"
git config --local user.email ""

git remote set-url origin https://arumakan1727:${GITHUB_TOKEN}@github.com/arumakan1727/kyopro-cpplib.git

git checkout -b master
git branch -a

template_cpp='./export/template.cpp'
short_snip='./export/short-snip.ultimate-vim-snippets'
long_snip='./export/long-snip.ultimate-vim-snippets'

cp ${template_cpp} ${template_cpp}.tmp
cp ${short_snip} ${short_snip}.tmp
cp ${long_snip} ${long_snip}.tmp

bash tool/export.sh

if ! diff ${template_cpp} ${template_cpp}.tmp -q ; then
  git add ${template_cpp}
  git commit -m "[auto] Update ${template_cpp}"
fi

if ! diff ${short_snip} ${short_snip}.tmp -q ; then
  git add ${short_snip}
  git commit -m "[auto] Update ${short_snip}"
fi

if ! diff ${long_snip} ${long_snip}.tmp -q ; then
  git add ${long_snip}
  git commit -m "[auto] Update ${long_snip}"
fi

git push origin HEAD
