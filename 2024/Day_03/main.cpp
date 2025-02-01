#include <cstdlib>
#include <fmt/base.h>
#include <fstream>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

void Part_1() {

  fmt::println("---------------- Part 1 ----------------");


}

int main(int argc, char *argv[]) {

  fmt::println("Advent Of Code 2024 - Day 3");

  std::ifstream dataFile{"input.txt"};

  if (!dataFile.is_open()) {
    std::cout << "Unable to open file - input.txt";
    return -1;
  }

  std::vector<std::string> data{};

  std::string line;

  while (std::getline(dataFile, line))
    data.push_back(line);

  dataFile.close();

  Part_1();

  return 0;
}
