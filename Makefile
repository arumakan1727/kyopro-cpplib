SHELL := /usr/bin/env bash -euo pipefail
SRC_DIR := src
FIND_C_CXX_FILES := find $(SRC_DIR) -type f -name '*.[ch]pp' -o -name '*.[ch]'


# Format and overwrite the source files.
.PHONY:	fmt
fmt:
	$(FIND_C_CXX_FILES) | xargs ./scripts/clang-format.sh

# Run lint & fmt-check
.PHONY:	check
check:	lint fmt-check

# Check whether the source files are formatted.
.PHONY:	fmt-check
fmt-check:
	$(FIND_C_CXX_FILES) | xargs clang-format --dry-run -Werror

# Check syntax & warnings of the source files.
.PHONY:	lint
lint:
	$(FIND_C_CXX_FILES) | xargs clang++ -Werror -fsyntax-only $$KPR_CXX_COMMON_FLAGS
