#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <iterator>
#include <array>

#include <spdlog/spdlog.h>

#define nBits 12

void Part1(const std::vector<std::bitset<nBits>> &data)
{
  std::bitset<nBits> gammaBits{};
  std::bitset<nBits> epsilonBits{};

  spdlog::info("Part 1!\n");

  for (auto i = 11; i > -1; --i) {
    int bitCount{ 0 };

    bitCount = std::count_if(data.begin(), data.end(), [i](const std::bitset<nBits> &bit) {
      return bit[i] == true;
    });

    if (bitCount >= static_cast<int>((data.size() / 2)))
      gammaBits[i] = true;
  }

  epsilonBits = gammaBits;
  epsilonBits.flip();

  spdlog::info("Gamma: {0}\n", gammaBits.to_string());
  spdlog::info("Epsilon: {0}\n", epsilonBits.to_string());
  spdlog::info("Total: {0}\n", gammaBits.to_ulong() * epsilonBits.to_ulong());
}

void Part2(const std::vector<std::bitset<nBits>> &data)
{
  const int bits = nBits;

  std::bitset<bits> oxygen_generator_rating;
  std::vector<std::bitset<bits>> most_common(data);

  for (int i = bits - 1; most_common.size() > 1 && i >= 0; i--) 
  {

    std::array<std::vector<std::bitset<bits>>, 2> filtered;
    for (auto diagnostic : most_common) 
      filtered[diagnostic[i]].push_back(diagnostic);

    most_common = filtered[0].size() > filtered[1].size() ? filtered[0] : filtered[1];
  }

  oxygen_generator_rating = most_common.at(0);

  std::bitset<bits> co2_scrubber_rating;
  std::vector<std::bitset<bits>> least_common(data);

  for (int i = bits - 1; least_common.size() > 1 && i >= 0; i--) 
  {

    std::array<std::vector<std::bitset<bits>>, 2> filtered;

    for (auto diagnostic : least_common) 
      filtered[diagnostic[i]].push_back(diagnostic);
    
    least_common = filtered[0].size() > filtered[1].size() ? filtered[1] : filtered[0];
  }

  co2_scrubber_rating = least_common.at(0);

  spdlog::info("Oxygen generator rating: {0}", oxygen_generator_rating.to_ulong());
  spdlog::info("Co2 scrubber ratin: {0}", co2_scrubber_rating.to_ulong());
  spdlog::info("Life support rating: {0}", oxygen_generator_rating.to_ulong() * co2_scrubber_rating.to_ulong());
}

int main(int, char **)
{
  spdlog::info("Day 3!\n");
  spdlog::info("Loading input.txt!\n");

  std::ifstream inFile("input.txt");

  if (!inFile.is_open() || inFile.fail()) {
    spdlog::warn("Failed to read input.txt!\n");
    return -1;
  }

  std::string line{};
  std::vector<std::bitset<nBits>> data{};

  while (inFile >> line) {
    std::bitset<nBits> bits{ line };
    data.push_back(bits);
  }

  Part1(data);
  Part2(data);

  return 0;
}
