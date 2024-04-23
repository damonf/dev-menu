find_package(Catch2 3 REQUIRED
  PATHS ${PROJECT_SOURCE_DIR}/third_party/bin/Catch2 NO_DEFAULT_PATH
  )

include_directories(
  SYSTEM
  "${PROJECT_SOURCE_DIR}/third_party/bin/Catch2/include"
)

add_executable(test-dev-menu)

add_subdirectory(dev-menu)

target_link_libraries(test-dev-menu
  PRIVATE
  dev-menu
  Catch2::Catch2WithMain
  )

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

include(CTest)
include(Catch)

# Run the function defined by the Catch2 CMake module
catch_discover_tests(test-dev-menu)
