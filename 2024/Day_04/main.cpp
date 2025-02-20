#include <cstdlib>
#include <filesystem>
#include <fmt/base.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using Grid = std::vector<std::vector<char>>;

void Part_1(const std::string &word, const Grid &grid) {
  fmt::println("---------------- Part 1 ----------------");

  if (word.empty() || grid.empty())
    return;

  auto result = 0;
  auto gW = grid[0].size();
  auto gH = grid.size();

  for (auto y = 0; y < gH; ++y) {
    for (auto x = 0; x < gW; ++x) {
      if (grid[y][x] != word.front())
        continue;

      for (auto dY = -1; dY < 2; ++dY) {
        for (auto dX = -1; dX < 2; ++dX) {
          if (dY == 0 && dX == 0)
            continue;

          for (auto wC = 1; wC < word.length(); ++wC) {
            auto tmpY = y + dY * wC;
            auto tmpX = x + dX * wC;

            if (tmpY < 0 || tmpY >= gH || tmpX < 0 || tmpX >= gW)
              break;
            else if (word[wC] != grid[tmpY][tmpX])
              break;
            else if (wC == word.length() - 1)
              result++;
          }
        }
      }
    }
  }

  fmt::println("Result: {}", result);
}

void Part_2(const Grid &grid) {

  fmt::println("---------------- Part 2 ----------------");

  auto result = 0;

  auto gW = grid[0].size();
  auto gH = grid.size();

  std::vector<std::pair<int, int>> directions{{-1, -1},
                                              {
                                                  1,
                                                  1,
                                              },
                                              {-1, 1},
                                              {1, -1}};

  for (auto y = 0; y < gH; ++y) {
    for (auto x = 0; x < gW; ++x) {

      if (grid[y][x] != 'A')
        continue;

      auto boundCheck = [&](const int dY, const int dX) {
        if (dY < 0 || dY >= gH || dX < 0 || dX >= gW)
          return false;

        return true;
      };

      auto checkDiagonal = [&](const std::pair<int, int> &diagA,
                               const std::pair<int, int> &diagB) {
        if (!boundCheck(y + diagA.first, x + diagA.second) ||
            !boundCheck(y + diagB.first, x + diagB.second))
          return false;

        return (grid[y + diagA.first][x + diagA.second] == 'M' &&
                grid[y + diagB.first][x + diagB.second] == 'S') ||
               (grid[y + diagA.first][x + diagA.second] == 'S' &&
                grid[y + diagB.first][x + diagB.second] == 'M');
      };

      auto lD = checkDiagonal(directions[0], directions[1]);
      auto rD = checkDiagonal(directions[2], directions[3]);

      if (!lD || !rD)
        continue;

      result++;
    }
  }

  fmt::println("Result: {}", result);
}

int main(int argc, char *argv[]) {

  fmt::println("Advent Of Code 2024 - Day 4");

  std::ifstream dataFile{"input.txt", std::ios::binary};

  if (!dataFile.is_open()) {
    std::cout << "Unable to open file - input.txt";
    return -1;
  }

  const auto fSize = std::filesystem::file_size("input.txt");

  std::string memory(fSize, '\0');
  dataFile.read(memory.data(), fSize);
  dataFile.close();

  Grid dataGrid{};
  std::istringstream stream(memory);
  std::string line{};

  while (std::getline(stream, line)) {
    std::vector<char> cv(line.begin(), line.end());
    dataGrid.emplace_back(cv);
  }

  Part_1("XMAS", dataGrid);
  Part_2(dataGrid);

  return 0;
}
