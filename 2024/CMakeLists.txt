set(DAYS
    01
    02
    03
    04)

# Loop over the set of years
foreach(DAY ${DAYS})
  # Dynamically generate the option for each year
  option(INCLUDE_DAY_${DAY} "Include ${DAY} year" ON)

  # Add subdirectory if the option is ON
  if (INCLUDE_DAY_${DAY})
    add_subdirectory(Day_${DAY})
  endif()
endforeach()
