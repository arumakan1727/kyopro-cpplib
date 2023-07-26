cmake_minimum_required(VERSION 3.21)
project(kyopro-cpplib CXX)
message("project name is automaically set as: ${PROJECT_NAME}")

set(PROJECT_VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(lib/Catch2)

add_executable(tests
  armkn/dbg/dbg.cpp
  armkn/dsu/union_find.cpp
  armkn/fmt/printer.cpp
  armkn/graph/mst/kruskal.cpp
  armkn/math/comb/binom_fn.cpp
  armkn/math/comb/binom_table.cpp
  armkn/math/comb/binom_table_const_n.cpp
  armkn/math/comb/factorials.cpp
  armkn/math/comb/lucas_binom.cpp
  armkn/math/integer/divisor_count_table.cpp
  armkn/math/integer/divisors.cpp
  armkn/math/integer/eratosthenes_sieve.cpp
  armkn/math/integer/ext_gcd.cpp
  armkn/math/integer/is_prime.cpp
  armkn/math/integer/osa_k.cpp
  armkn/math/integer/prime_factorize.cpp
  armkn/math/integer/prime_numbers.cpp
  armkn/rangefold/cumulative_sum.cpp
  armkn/rangefold/fenwick_tree.cpp
  armkn/str/rolling_hash.cpp
  armkn/util/alias/heapq.cpp
  armkn/util/fn/floor_pow2.cpp
  armkn/util/fn/ilog2.cpp
  armkn/util/fn/isqrt.cpp
  armkn/util/fn/runlength.cpp
  armkn/util/fn/sigma.cpp
)
target_include_directories(tests PRIVATE
  ../src
  lib/Catch2/src
)
target_compile_options(tests PRIVATE
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
  -Werror

  -g
)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
