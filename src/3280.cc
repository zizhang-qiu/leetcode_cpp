#include <algorithm>
#include <bitset>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  std::string intToBinary(int number) {
    if (number == 0)
      return "0";

    std::string binary = "";
    while (number > 0) {
      binary = std::to_string(number % 2) + binary;
      number /= 2;
    }
    return binary;
  }

  string convertDateToBinary(string date) {
    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);
    std::string year_binary = intToBinary(std::stoi(year));
    std::string month_binary = intToBinary(std::stoi(month));
    std::string day_binary = intToBinary(std::stoi(day));
    return year_binary + '-' + month_binary + '-' + day_binary;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  Solution sl;
  std::string date = "2080-02-29";
  auto res = sl.convertDateToBinary(date);
  std::cout << res << "\n";
  return 0;
}
