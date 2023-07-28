SHELL := /usr/bin/env bash -euo pipefail
.DEFAULT_GOAL := check
SRC_DIR := src
TESTS_DIR := tests
ALL_CXX_FILES := find $(SRC_DIR) $(TESTS_DIR)/armkn -type f -name '*.[ch]pp'
SRC_CXX_FILES := find $(SRC_DIR) -type f -name '*.[ch]pp'

.PHONY:	fmt check fmt-check lint test

# Format and overwrite the source files.
fmt:
	@echo "--- formatting ---"
	$(ALL_CXX_FILES) | xargs ./scripts/clang-format.sh

# Run lint & fmt-check
check:	lint fmt-check

# Check whether the source files are formatted.
fmt-check:
	@echo "--- checking format ---"
	$(ALL_CXX_FILES) | xargs clang-format --dry-run -Werror

# Check syntax & warnings of the source files.
lint:
	@echo "--- linting ---"
	$(ALL_CXX_FILES) | xargs ./scripts/mylint.py
	clang-tidy --verify-config
	$(SRC_CXX_FILES) | xargs clang-tidy

test:
	make -C tests run/debug

requirements.txt:	poetry.lock
	poetry export > $@
