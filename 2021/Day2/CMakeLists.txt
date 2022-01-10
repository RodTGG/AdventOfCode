find_package(spdlog)

configure_file(input.txt input.txt COPYONLY)

add_executable(2021_Day2 main.cpp)
target_link_libraries(
    2021_Day2
    PRIVATE project_options
          project_warnings
          spdlog::spdlog)