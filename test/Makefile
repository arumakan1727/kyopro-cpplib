SRC := $(wildcard *.test.cpp)
BUILD_DIR := build
BINS := $(addprefix ${BUILD_DIR}/, ${SRC:.cpp=.bin})
DEPENDS := ${BINS:.bin=.depends}
CXX_FLAGS := @../compile_flags.txt
CXX := g++
BITS_DIR := ../bits-dir

.PHONY:	variables all clean


variables:
	@echo -e "SRC:\n ${SRC}"
	@echo -e "BUILD_DIR:\n  ${BUILD_DIR}"
	@echo -e "DEPENDS:\n  ${DEPENDS}"
	@echo -e "BINS:\n  ${BINS}"
	@echo -e "CXX_FLAGS:\n  ${CXX_FLAGS}"
	@echo -e "CXX:\n  ${CXX}"
	@echo -e "BITS_DIR:\n  ${BITS_DIR}"


all: ${BINS}


${BUILD_DIR}/%.bin:	./%.cpp
	@[ -d ${BUILD_DIR} ] || mkdir -p ${BUILD_DIR}
	${CXX} ${CXX_FLAGS} -isystem ${BITS_DIR} $< -o $@


${BUILD_DIR}/%.depends:	%.cpp
	@echo "Creating depends file: $@ of $<"
	@[ -d ${BUILD_DIR} ] || mkdir -p ${BUILD_DIR}
	set -e; ${CXX} -E -MM $< \
		| sed '1s|\($*\)\.o[ :]*|${BUILD_DIR}/\1.bin $@ : |' > $@; \
		[ -s $@ ] || rm -f $@


clean:
	rm -rf ${BUILD_DIR}

-include ${DEPENDS}
