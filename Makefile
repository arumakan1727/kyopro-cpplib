SHELL := /usr/bin/env bash

.PHONY:	fmt
fmt:
	find src -type f -name '*.[ch]pp' | xargs clang-format -i
