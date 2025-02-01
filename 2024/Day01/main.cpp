#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void printDataVector(std::vector<int> &data) {
  for (auto d : data)
    std::cout << d << "\n";
}

void Part1(std::vector<int> &left, std::vector<int> &right) {
  auto distanceSum = 0;

  std::cout << "------- Part 1 -------\n";

  for (auto i = 0; i < left.size(); ++i) {
    distanceSum += std::abs(left[i] - right[i]);
    std::cout << left[i] << " - " << right[i] << " = " << distanceSum << "\n";
  }

  std::cout << "Distance Sum = " << distanceSum << "\n";
}

void Part2(std::vector<int> &left, std::vector<int> &right) {

  std::cout << "------- Part 2 -------\n";

  auto similarityScore = 0;

  for (auto d : left) {
    auto dOccurrence = std::count(right.begin(), right.end(), d);
    similarityScore += d * dOccurrence;
    std::cout << "Data = " << d << ", n " << dOccurrence << "\n";
  }

  std::cout << "Similarity Score = " << similarityScore << "\n";
}

int main(int argc, char *argv[]) {

  std::cout << "Advent Of Code 2024 - Day 1\n";

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

  std::vector<int> left{};
  std::vector<int> right{};

  for (auto d : data) {
    auto leftData = std::stoi(d.substr(0, d.find(" ")));
    auto rightData = std::stoi(d.substr(d.find_last_of(" ") + 1, d.length()));

    left.push_back(leftData);
    right.push_back(rightData);

    std::cout << "Left = " << leftData << ", Right = " << rightData << "\n";
  }

  std::sort(left.begin(), left.end());

  // std::cout << "Left Data" << "\n";
  // printDataVector(left);

  std::sort(right.begin(), right.end());

  // std::cout << "Right Data" << "\n";
  // printDataVector(right);

  Part1(left, right);
  Part2(left, right);

  return 0;
}
