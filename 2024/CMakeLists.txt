option(INCLUDE_2024_01 "Include 2024 Day 1" ON)
option(INCLUDE_2024_02 "Include 2024 Day 2" ON)

if(INCLUDE_2024_01)
  add_subdirectory(Day01)
endif()

if(INCLUDE_2024_02)
  add_subdirectory(Day02)
endif()
