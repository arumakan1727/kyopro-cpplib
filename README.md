# kyopro-cpplib

[![Actions Status](https://github.com/arumakan1727/Kyopro-Cpplib/workflows/verify/badge.svg)](https://github.com/arumakan1727/Kyopro-Cpplib/actions)
[![GitHub Pages](https://img.shields.io/static/v1?label=GitHub+Pages&message=+&color=brightgreen&logo=github)](https://arumakan1727.github.io/kyopro-cpplib/)
[![C++ Version](https://img.shields.io/badge/GCC-c%2B%2B17-blue)](https://github.com/arumakan1727/kyopro-cpplib/blob/master/.verify-helper/config.toml)

GCC の `-std=c++17` のみで Verify しています。

[Online Judge Verification Helper](https://github.com/online-judge-tools/verification-helper) で管理されています。

MIT ライセンスです。このライブラリを利用したことで何か問題が起きても作者は責任を負いません。

- `[A-Z]*/`: ライブラリ本体です。
- `export/template.cpp`: 競プロ用のテンプレートです。`export/template-prototype.cpp` から生成されました。
- `export/short-snippet.vscode.json`: プレースホルダーを含み得る短めのスニペットです。
- `export/snippet.vscode.json`: `[A-Z]*/` 以下のソースファイルを纏めたスニペットです。

スニペットファイルは vscode の Project snippet 用です。
vscode プロジェクトの `.vscode/` 内に `.code-snippets` の拡張子のシンボリックリンクを作成し、そこからこのライブラリの JSON ファイルを参照して使うことを想定しています (もっと良い方法があるかもしれません)。
