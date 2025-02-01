configure_file(input.txt input.txt COPYONLY)

add_executable(Day02 main.cpp)

target_link_libraries(Day02 PRIVATE fmt::fmt)
