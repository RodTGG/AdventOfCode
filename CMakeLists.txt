cmake_minimum_required(VERSION 3.14)

include(FetchContent)

fetchcontent_declare(fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG master)

fetchcontent_makeavailable(fmt)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(AdventOfCode)

option(INCLUDE_2024 "Include year 2024" ON)

if(INCLUDE_2024)
  add_subdirectory(2024)
endif()
