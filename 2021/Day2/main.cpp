#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>

#include <spdlog/spdlog.h>

void Part1(const std::vector<std::pair<std::string, int>> &data)
{
  std::pair<int, int> position{ 0, 0 };

  spdlog::info("Part 1!\n");

  for (auto &d : data) {
    if (d.first == "forward")
      position.first += d.second;
    else if (d.first == "down")
      position.second += d.second;
    else if (d.first == "up")
      position.second -= d.second;
  }

  spdlog::info("Final Position: {0}x{1}\n", position.first, position.second);
  spdlog::info("Total: {0}\n", position.first * position.second);
}

void Part2(const std::vector<std::pair<std::string, int>> &data)
{
  int aim{ 0 };
  std::pair<int, int> position{ 0, 0 };

  spdlog::info("Part 2!\n");

  for (auto &d : data) {
    if (d.first == "forward") {
      position.first += d.second;
      position.second += aim * d.second;
    } else if (d.first == "down") {
      aim += d.second;
    } else if (d.first == "up") {
      aim -= d.second;
    }
  }

  spdlog::info("Final Position: {0}x{1}\n", position.first, position.second);
  spdlog::info("Total: {0}\n", position.first * position.second);
}

int main(int, char **)
{
  spdlog::info("Day 2!\n");
  spdlog::info("Loading input.txt!\n");

  std::ifstream inFile("input.txt");

  if (!inFile.is_open() || inFile.fail()) {
    spdlog::warn("Failed to read input.txt!\n");
    return -1;
  }

  std::string direction{};
  int change{};

  std::vector<std::pair<std::string, int>> data{};

  while (inFile >> direction >> change)
    data.push_back({ direction, change });

  Part1(data);
  Part2(data);

  return 0;
}
