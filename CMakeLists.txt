cmake_minimum_required(VERSION 3.25)

project(
    DevMenuCPP
    VERSION 1.0
    DESCRIPTION "Dev Menu"
    LANGUAGES CXX
    )

# generate the test target
enable_testing()

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# ensure -std=c++xx instead of -std=g++xx
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(
  -Wall
  -Wextra
  -Wwrite-strings
  -Wno-parentheses
  -Wno-comment
  -Wpedantic
  -Warray-bounds
  -Weffc++
  )

# run clang-tidy
set(CMAKE_CXX_CLANG_TIDY 
  clang-tidy;
  -header-filter=${CMAKE_CURRENT_SOURCE_DIR};
  )

add_subdirectory(apps)
add_subdirectory(src)
add_subdirectory(tests)
