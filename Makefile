SHELL := /usr/bin/env bash -euo pipefail
.DEFAULT_GOAL := check
SRC_DIR := src
TESTS_DIR := tests
ALL_C_CXX_FILES := find $(SRC_DIR) $(TESTS_DIR)/armkn -type f -name '*.[ch]pp' -o -name '*.[ch]'
SRC_C_CXX_FILES := find $(SRC_DIR) -type f -name '*.[ch]pp' -o -name '*.[ch]'


# Format and overwrite the source files.
.PHONY:	fmt
fmt:
	@echo "--- formatting ---"
	$(ALL_C_CXX_FILES) | xargs ./scripts/clang-format.sh

# Run lint & fmt-check
.PHONY:	check
check:	lint fmt-check

# Check whether the source files are formatted.
.PHONY:	fmt-check
fmt-check:
	@echo "--- checking format ---"
	$(ALL_C_CXX_FILES) | xargs clang-format --dry-run -Werror

# Check syntax & warnings of the source files.
.PHONY:	lint
lint:
	@echo "--- linting ---"
	$(SRC_C_CXX_FILES) | xargs ./scripts/mylint.py
	$(SRC_C_CXX_FILES) | xargs clang++ -Werror -fsyntax-only $$KPR_CXX_COMMON_FLAGS

.PHONY:	test
test:
	make -C tests run
