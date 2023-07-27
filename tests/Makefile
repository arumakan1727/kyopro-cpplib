DEBUG_BIN       := build/debug/tests
DEBUG_MKFILE    := build/debug/Makefile
RELEASE_BIN     := build/release/tests
RELEASE_MKFILE  := build/release/Makefile
LIB_CATCH2_VER  := 3.4.0
N_BUILD_PRALLEL ?= 4
.DEFAULT_GOAL   := $(DEBUG_BIN)

#----- phony tasks ------
.PHONY:	setup clean
.PHONY:	run/debug run/debug/verbose run/relase
.PHONY:	$(DEBUG_BIN) $(RELEASE_BIN)

setup:	compile_flags.txt lib/Catch2 $(DEBUG_MKFILE) $(RELEASE_MKFILE)

clean:
	rm -rf build lib/Catch2

run/debug:	$(DEBUG_BIN)
	$<

run/debug/verbose:	$(DEBUG_BIN)
	$< -s

run/release:	$(RELEASE_BIN)
	$<

build/debug/tests:	$(DEBUG_MKFILE)
	make -C $(dir $@) -j$(N_BUILD_PRALLEL)

build/release/tests:	$(RELEASE_MKFILE)
	make -C $(dir $@) -j$(N_BUILD_PRALLEL)

#----- non-phony tasks ------
compile_flags.txt:	scripts/gen_compile_flags_txt.sh
	$< > compile_flags.txt

lib/Catch2:
	curl -sSL https://github.com/catchorg/Catch2/archive/refs/tags/v$(LIB_CATCH2_VER).tar.gz | tar zx && mv Catch2-$(LIB_CATCH2_VER) $@

$(DEBUG_MKFILE):	CMakeLists.txt
	cmake -S . -B $(dir $@) -DCMAKE_BUILD_TYPE=Debug

$(RELEASE_MKFILE):	CMakeLists.txt
	cmake -S . -B $(dir $@) -DCMAKE_BUILD_TYPE=Release
