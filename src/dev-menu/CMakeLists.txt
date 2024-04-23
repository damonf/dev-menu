target_sources(dev-menu
  PRIVATE
  arg_parser.cpp
  arg_parser.hpp
  paths.cpp
  paths.hpp
  menu_option.cpp
  menu_option.hpp
  menu.cpp
  menu.hpp
  is_number.hpp
  trim.hpp
  trim.cpp
  )

target_include_directories(dev-menu PUBLIC ${CMAKE_CURRENT_LIST_DIR})
