#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

#include <spdlog/spdlog.h>

int main(int, char **)
{
  spdlog::info("Day 4!\n");
  spdlog::info("Loading input.txt!\n");

  std::ifstream inFile("input.txt");

  if (!inFile.is_open() || inFile.fail()) {
    spdlog::warn("Failed to read input.txt!\n");
    return -1;
  }

  std::string line{};

  while (inFile >> line) {
    spdlog::info(line);
  }

  return 0;
}
