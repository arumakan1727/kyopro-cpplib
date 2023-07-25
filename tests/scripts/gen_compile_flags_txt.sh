#!/usr/bin/env bash
set -euo pipefail

scriptDir=$(cd "$(dirname "${BASH_SOURCE[0]}")" &>/dev/null && pwd -P)
repoRoot=$(realpath "$scriptDir/../..")

cat <<EOT
-std=c++17
-I${repoRoot}/src
-I${repoRoot}/tests/lib/Catch2/src
-I${repoRoot}/tests/build/lib/Catch2/generated-includes
-Wall
-Wextra
-DARMKN_DEBUG

-Wconversion
-Wfloat-equal
-Winit-self
-Winvalid-pch
-Wmissing-include-dirs
-Wshadow
-Wswitch-enum

-Wno-sign-conversion
EOT
