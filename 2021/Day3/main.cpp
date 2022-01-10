#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>

#include <spdlog/spdlog.h>

void Part1(const std::vector<std::pair<std::string, int>> &data)
{
  spdlog::info("Part 3!\n");
}

//void Part2(const std::vector<std::pair<std::string, int>> &data)
//{
//  
//}

int main(int, char **)
{
  spdlog::info("Day 3!\n");
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
  //Part2(data);

  return 0;
}
