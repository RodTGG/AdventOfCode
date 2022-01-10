#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

#include <spdlog/spdlog.h>

void Part1(const std::vector<int> &data)
{
  int total{ 0 };

  spdlog::info("Part 1!\n");

  for (size_t i{ 1 }; i < data.size(); ++i)
    if (data[i] > data[i - 1])
      ++total;

  spdlog::info("Total: {0}\n", total);
}

void Part2(const std::vector<int> &data)
{
  int total{ 0 };

  spdlog::info("Part 2!\n");

  for (size_t i{ 3 }; i < data.size(); ++i)
    if ((data[i] + data[i - 1] + data[i - 2]) > (data[i - 1] + data[i - 2] + data[i - 3]))
      ++total;

  spdlog::info("Total: {0}\n", total);
}

int main(int, char **)
{
  spdlog::info("Day 1!\n");
  spdlog::info("Loading input.txt!\n");

  std::ifstream inFile("input.txt");

  if (!inFile.is_open() || inFile.fail()) {
    spdlog::warn("Failed to read input.txt!\n");
    return -1;
  }

  int depth{ 0 };
  std::vector<int> data{};

  while (inFile >> depth)
    data.push_back(depth);

  Part1(data);
  Part2(data);

  return 0;
}
