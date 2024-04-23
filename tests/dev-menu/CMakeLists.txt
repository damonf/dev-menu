target_sources(test-dev-menu
    PRIVATE
      arg_parser_test.cpp
      menu_test.cpp
      trim_test.cpp
      menu_option_test.cpp
)

target_include_directories(test-dev-menu PUBLIC ${CMAKE_CURRENT_LIST_DIR})

