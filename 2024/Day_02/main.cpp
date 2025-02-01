#include <cstdlib>
#include <fmt/base.h>
#include <fstream>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

using Level = std::vector<int>;
using LevelContainer = std::vector<Level>;

Level ParseLevel(const std::string &line) {
  auto split_view = line | std::ranges::views::split(' ');

  Level tokens{};

  for (const auto token : split_view)
    tokens.push_back(std::stoi(std::string(token.begin(), token.end())));

  return tokens;
}

void Part_1(const LevelContainer &container) {

  fmt::println("---------------- Part 1 ----------------");

  int nSafe = 0;

  for (auto l : container) {
    auto isSafe = true;
    auto direction = false;
    auto currentDirection = false;

    for (auto i = 0; i < l.size() - 1; ++i) {
      auto range = l[i] - l[i + 1];

      if (i == 0)
        direction = range < 0;

      currentDirection = range < 0;

      if (direction != currentDirection) {
        isSafe = false;
        fmt::println("Not Safe - bad direction");
        break;
      }

      auto absRange = std::abs(range);

      if (absRange < 1 || absRange > 3) {
        isSafe = false;
        fmt::println("Not Safe - bad range");
        break;
      }
    }

    if (isSafe) {
      nSafe++;
      fmt::println("Safe");
    }
  }

  fmt::println("Safe Levels - {}", nSafe);
}

int isLevelSafe(const Level &level) {
  if (level.size() == 1)
    return -1;

  auto direction = level[0] - level[1] >= 0;

  for (auto i = 0; i < level.size() - 1; ++i) {
    auto range = level[i] - level[i + 1];
    auto distance = std::abs(range);
    auto currentDirection = range >= 0;

    if (currentDirection != direction || distance < 1 || distance > 3)
      return i;
  }

  return -1;
}

bool removeReportAndCheck(const Level &l, int idx) {
  auto tmpLevel = l;

  tmpLevel.erase(tmpLevel.begin() + idx);

  return isLevelSafe(tmpLevel) == -1;
}

void Part_2(const LevelContainer &container) {

  fmt::println("---------------- Part 2 ----------------");

  int nSafe = 0;

  for (const auto &l : container) {
    auto badReportIdx = isLevelSafe(l);

    if (badReportIdx == -1) {
      nSafe++;
    } else {
      if (removeReportAndCheck(l, badReportIdx)) {
        nSafe++;
      } else if (badReportIdx + 1 < l.size() &&
                 removeReportAndCheck(l, badReportIdx + 1)) {
        nSafe++;
      } else if (badReportIdx > 0 &&
                 removeReportAndCheck(l, badReportIdx - 1)) {
        nSafe++;
      }
    }
  }

  fmt::println("Safe Levels - {}", nSafe);
}

int main(int argc, char *argv[]) {

  fmt::println("Advent Of Code 2024 - Day 2");

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

  LevelContainer container{};

  for (auto l : data) {
    container.push_back(ParseLevel(l));
  }

  for (auto l : container) {
    for (auto x : l) {
      fmt::print("{} ", x);
    }

    fmt::println("");
  }

  Part_1(container);
  Part_2(container);

  return 0;
}
