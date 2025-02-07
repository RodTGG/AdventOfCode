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

void Part_1(const std::string &memory) {
  fmt::println("---------------- Part 1 ----------------");

  std::regex mul_exppresion(R"(mul\((\d+),(\d+\)))",
                            std::regex_constants::ECMAScript |
                                std::regex_constants::icase);

  auto iterBegin =
      std::sregex_iterator(memory.begin(), memory.end(), mul_exppresion);
  auto iterEnd = std::sregex_iterator();

  auto nMatches = std::distance(iterBegin, iterEnd);
  std::vector<int> results(nMatches);

  for (std::sregex_iterator i = iterBegin; i != iterEnd; ++i) {
    std::smatch match = *i;

    auto x = std::stoi(match[1]);
    auto y = std::stoi(match[2]);

    auto result = x * y;

    results.emplace_back(result);
  }

  auto total = std::accumulate(results.begin(), results.end(), 0);

  fmt::println("nMatches: {}", nMatches);
  fmt::println("Total: {}", total);
}

void Part_2(const std::string &memory) {

  fmt::println("---------------- Part 2 ----------------");

  std::regex mul_exppresion(R"((don't\(\))|(do\(\))|(mul\((\d+),(\d+)\)))",
                            std::regex_constants::ECMAScript |
                                std::regex_constants::icase);

  auto iterBegin =
      std::sregex_iterator(memory.begin(), memory.end(), mul_exppresion);
  auto iterEnd = std::sregex_iterator();

  auto canMultiply = true;

  auto nMatches = 0;
  std::vector<int> results{};

  for (std::sregex_iterator i = iterBegin; i != iterEnd; ++i) {
    std::smatch match = *i;

    if (match[1].matched) {
      canMultiply = false;
      fmt::println("Multiply Disabled");
    } else if (match[2].matched) {
      canMultiply = true;
      fmt::println("Multiply Enabled");
    } else if (match[3].matched && canMultiply) {

      auto x = std::stoi(match[4]);
      auto y = std::stoi(match[5]);

      auto result = x * y;

      results.emplace_back(result);

      nMatches++;
    }
  }

  auto total = std::accumulate(results.begin(), results.end(), 0);

  fmt::println("nMatches: {}", nMatches);
  fmt::println("Total: {}", total);
}

int main(int argc, char *argv[]) {

  fmt::println("Advent Of Code 2024 - Day 3");

  std::ifstream dataFile{"input.txt", std::ios::binary};

  if (!dataFile.is_open()) {
    std::cout << "Unable to open file - input.txt";
    return -1;
  }

  const auto fSize = std::filesystem::file_size("input.txt");

  std::string memory(fSize, '\0');
  dataFile.read(memory.data(), fSize);

  dataFile.close();

  Part_1(memory);
  Part_2(memory);

  return 0;
}
