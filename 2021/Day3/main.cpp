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

enum class FilterType {
  Common,
  LeastCommon
};

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
  std::bitset<nBits> oxygen{};
  std::bitset<nBits> co2{};

  spdlog::info("Part 2!\n");

  std::vector<std::bitset<nBits>> tmp = data;

  for (auto i = 11; i > -1; --i) {
    int bitCount{ 0 };
    bool mostCommonBit{ false };

    if (tmp.size() <= 1)
      break;

    bitCount = std::count_if(tmp.begin(), tmp.end(), [i](const std::bitset<nBits> &bit) {
      return bit[i] == true;
    });

    mostCommonBit = bitCount >= static_cast<int>(((tmp.size() + 2 - 1) / 2));

    tmp.erase(std::remove_if(tmp.begin(), tmp.end(), [i, mostCommonBit](const std::bitset<nBits> &bit) { return bit[i] != mostCommonBit; }), tmp.end());
  }

  oxygen = tmp.front();
  tmp = data;

  for (auto i = 11; i > -1; --i) {
    int bitCount{ 0 };
    bool leastCommonBit{ false };

    if (tmp.size() <= 1)
      break;

    bitCount = std::count_if(tmp.begin(), tmp.end(), [i](const std::bitset<nBits> &bit) {
      return bit[i] == true;
    });

    if (bitCount == 1)
      leastCommonBit = false;
    else
      leastCommonBit = bitCount <= static_cast<int>(((tmp.size() + 2 - 1) / 2));

    tmp.erase(std::remove_if(tmp.begin(), tmp.end(), [i, leastCommonBit](const std::bitset<nBits> &bit) { return bit[i] != leastCommonBit; }), tmp.end());
  }

  co2 = tmp.front();

  spdlog::info("Oxygen: {0}", oxygen.to_string());
  spdlog::info("C02: {0}", co2.to_string());
  spdlog::info("Total: {0}\n", oxygen.to_ulong() * co2.to_ulong());
}

std::vector<std::bitset<nBits>> filter_data(const std::vector<std::bitset<nBits>> &data, FilterType filter = FilterType::Common)
{
  std::vector<std::bitset<nBits>> result{ data };  

  return result;
}

void test()
{
  const int bits = nBits;// nBits bit numbers

  std::vector<std::bitset<bits>> diagnostics;
  std::ifstream fin("input.txt");
  std::string line;

  while (fin >> line) {
    diagnostics.push_back(std::bitset<bits>(line));
  }

  std::bitset<bits> oxygen_generator_rating;

  std::vector<std::bitset<bits>> most_common(diagnostics);// avoid changing input by duplicating
  for (int i = bits - 1; most_common.size() > 1 && i >= 0; i--) {
    std::array<std::vector<std::bitset<bits>>, 2> filtered;
    for (auto diagnostic : most_common) {
      filtered[diagnostic[i]].push_back(diagnostic);
    }
    most_common = filtered[0].size() > filtered[1].size() ? filtered[0] : filtered[1];
    //if equal, keep 1
  }
  oxygen_generator_rating = most_common.at(0);

  std::bitset<bits> co2_scrubber_rating;

  std::vector<std::bitset<bits>> least_common(diagnostics);//avoid changing input by duplicating
  for (int i = bits - 1; least_common.size() > 1 && i >= 0; i--) {
    std::array<std::vector<std::bitset<bits>>, 2> filtered;
    for (auto diagnostic : least_common) {
      filtered[diagnostic[i]].push_back(diagnostic);
    }
    least_common = filtered[0].size() > filtered[1].size() ? filtered[1] : filtered[0];
    // if equal, keep 0
  }
  co2_scrubber_rating = least_common.at(0);

  // convert to unsigned long int
  std::cout << "Oxygen generator rating : " << oxygen_generator_rating.to_ulong() << std::endl;
  std::cout << "Co2 scrubber rating : " << co2_scrubber_rating.to_ulong() << std::endl;
  std::cout << "Life support rating : " << oxygen_generator_rating.to_ulong() * co2_scrubber_rating.to_ulong() << std::endl;
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
  test();

  return 0;
}
