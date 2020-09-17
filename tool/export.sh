#!/usr/bin/env bash
set -eux

script_dir=$(cd $(dirname $0); pwd)
export_dir=$script_dir/../export

python3 $script_dir/gen-template.py > $export_dir/template.cpp
python3 $script_dir/gen-snippet.py --short-snippets > $export_dir/short-snip.ultimate-vim-snippets
python3 $script_dir/gen-snippet.py --long-snippets > $export_dir/long-snip.ultimate-vim-snippets
