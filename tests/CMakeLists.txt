cmake_minimum_required(VERSION 3.21)
project(kyopro-cpplib CXX)
message("project name is automaically set as: ${PROJECT_NAME}")
message("build type: ${CMAKE_BUILD_TYPE}")
message("build tool: ${CMAKE_BUILD_TOOL}")

set(PROJECT_VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(lib/Catch2)

add_executable(tests
  armkn/algo/mapping/cycle_finder.cpp
  armkn/algo/mapping/doubling.cpp
  armkn/algo/mapping/doubling_with_monoid.cpp
  armkn/algo/numeric/bin_search_integer.cpp
  armkn/dp/k_choose_prod_sum.cpp
  armkn/dsu/union_find.cpp
  armkn/fmt/printer.cpp
  armkn/graph/mst/kruskal.cpp
  armkn/graph/tree/rooted_tree.cpp
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
  armkn/rangefold/cumulative_sum_2d.cpp
  armkn/rangefold/fenwick_tree.cpp
  armkn/set/closed_range.cpp
  armkn/set/closed_range_set.cpp
  armkn/str/rolling_hash.cpp
  armkn/util/alias/heapq.cpp
  armkn/util/constants/infinity.cpp
  armkn/util/dbg.cpp
  armkn/util/fn/floor_pow2.cpp
  armkn/util/fn/ilog2.cpp
  armkn/util/fn/isqrt.cpp
  armkn/util/fn/match_2d.cpp
  armkn/util/fn/rotate_matrix.cpp
  armkn/util/fn/runlength.cpp
  armkn/util/fn/sigma.cpp
  armkn/util/type_traits/is_iterable.cpp
  armkn/util/type_traits/is_key_value_map.cpp
  armkn/util/type_traits/is_random_accessible.cpp
  armkn/util/type_traits/is_string_like.cpp
)

target_include_directories(tests PRIVATE
  ../src
  lib/Catch2/src
)

string(APPEND CMAKE_CXX_FLAGS
  " -Wall -Wextra -Werror"
  " -Wconversion"
  " -Wdelete-non-virtual-dtor"
  " -Wfloat-equal"
  " -Winit-self"
  " -Winvalid-pch"
  " -Wmissing-include-dirs"
  " -Woverloaded-virtual"
  " -Wreorder"
  " -Wshadow"
  " -Wsuggest-override"
  " -Wswitch-enum"
  " -Wwrite-strings"
  " -Wno-sign-conversion"
)
set(CMAKE_CXX_FLAGS_DEBUG "-g -DARMKN_DEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG -mtune=native -march=native")

if(UNIX AND NOT APPLE)
  string(APPEND CMAKE_CXX_FLAGS_DEBUG " -fno-omit-frame-pointer -fsanitize=address,undefined")
endif()

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  string(APPEND CMAKE_CXX_FLAGS " -Wno-unknown-pragmas")
endif()

message("CMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}")
message("CMAKE_CXX_FLAGS_DEBUG=${CMAKE_CXX_FLAGS_DEBUG}")
message("CMAKE_CXX_FLAGS_RELEASE=${CMAKE_CXX_FLAGS_RELEASE}")

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
