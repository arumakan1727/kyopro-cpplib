cmake_minimum_required(VERSION 3.21)
project(kyopro-cpplib CXX)
message("project name is automaically set as: ${PROJECT_NAME}")

set(PROJECT_VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(lib/Catch2)

add_executable(tests
  armkn/fmt/printer.cpp
  armkn/util/fn/sigma.cpp
)
target_include_directories(tests PRIVATE
  ../src
  lib/Catch2/src
)
target_compile_options(tests PRIVATE
  -Wall -Wextra -Wconversion
  -Werror
  -Wno-sign-conversion
)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
