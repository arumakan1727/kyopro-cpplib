#!/usr/bin/env bash
set -euo pipefail

scriptDir=$(cd "$(dirname "${BASH_SOURCE[0]}")" &>/dev/null && pwd -P)
repoRoot=$(realpath "$scriptDir/../..")

cat <<EOT
-std=c++17
-I${repoRoot}/src
-I${repoRoot}/tests/lib/Catch2/src
-I${repoRoot}/tests/build/debug/lib/Catch2/generated-includes
-DARMKN_DEBUG
-Wall
-Wextra

-Wconversion
-Wdelete-non-virtual-dtor
-Wfloat-equal
-Winit-self
-Winvalid-pch
-Wmissing-include-dirs
-Woverloaded-virtual
-Wreorder
-Wshadow
-Wsuggest-override
-Wswitch-enum
-Wwrite-strings

-Wno-sign-conversion
EOT
