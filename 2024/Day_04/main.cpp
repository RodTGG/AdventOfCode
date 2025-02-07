#include <cstdlib>
#include <filesystem>
#include <fmt/base.h>
#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ranges>
#include <regex>
#include <string>
#include <vector>
#include <sstream>

void Part_1(const std::vector<std::string> data) {
  fmt::println("---------------- Part 1 ----------------");


}

int main(int argc, char *argv[]) {

  fmt::println("Advent Of Code 2024 - Day 3");

  std::ifstream dataFile{"input.txt", std::ios::binary};

  if (!dataFile.is_open()) {
    std::cout << "Unable to open file - input.txt";
    return -1;
  }

  const auto fSize = std::filesystem::file_size("input.txt");

  std::string fileBuffer(fSize, '\0');
  dataFile.read(fileBuffer.data(), fSize);
  dataFile.close();

  std::vector<std::string> data{};
  std::istringstream stream(fileBuffer);
  std::string line{};

  while (std::getline(stream, line))
        data.emplace_back(line);

  Part_1(data);

  return 0;
}
