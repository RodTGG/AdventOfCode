configure_file(input.txt input.txt COPYONLY)

add_executable(Day04 main.cpp)

target_link_libraries(Day04 PRIVATE fmt::fmt)
