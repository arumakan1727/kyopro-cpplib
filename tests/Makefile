.DEFAULT_GOAL := build/tests
TESTS_BIN := build/tests
LIB_CATCH2_VER := 3.4.0

.PHONY:	setup
setup:	compile_flags.txt download/Catch2 build/Makefile


.PHONY:	clean
clean:
	rm -rf build


.PHONY:	compile_flags.txt
compile_flags.txt:
	./scripts/gen_compile_flags_txt.sh > compile_flags.txt


.PHONY:	download/Catch2
download/Catch2:
	rm -rf lib/Catch2
	curl -sSL https://github.com/catchorg/Catch2/archive/refs/tags/v$(LIB_CATCH2_VER).tar.gz | tar zx && mv Catch2-$(LIB_CATCH2_VER) lib/Catch2


.PHONY:	run
run:	build/tests
	$(TESTS_BIN)


.PHONY:	run/verbose
run/verbose:	build/tests
	$(TESTS_BIN) -s


.PHONY:	info/test/list
info/test/list:	build/tests
	@echo "--------------------------"
	$(TESTS_BIN) --list-tests


.PHONY:	info/test/tags
info/test/tags:	build/tests
	@echo "--------------------------"
	$(TESTS_BIN) --list-tags


.PHONY:	build/tests
build/tests:	build/Makefile
	make -C build -j4


build/Makefile:	CMakeLists.txt
	cmake -S . -B build
