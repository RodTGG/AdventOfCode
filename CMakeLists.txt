cmake_minimum_required(VERSION 3.14)

include(FetchContent)

# Fetch fmt library
FetchContent_Declare(fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG master
)
FetchContent_MakeAvailable(fmt)

# Set C++ standard and project
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(AdventOfCode)

# Define a set of years
set(YEARS 2024)

# Loop over the set of years
foreach(YEAR ${YEARS})
  # Dynamically generate the option for each year
  option(INCLUDE_${YEAR} "Include ${YEAR} year" ON)

  # Add subdirectory if the option is ON
  if (INCLUDE_${YEAR})
    add_subdirectory(${YEAR})
  endif()
endforeach()
