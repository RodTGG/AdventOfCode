configure_file(input.txt input.txt COPYONLY)

add_executable(Day03 main.cpp)

target_link_libraries(Day03 PRIVATE fmt::fmt)
