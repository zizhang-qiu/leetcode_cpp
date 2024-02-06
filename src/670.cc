//
// Created by qzz on 2024/1/22.
//
#include <iostream>
#include <vector>
#include <string>

class Solution {
  public:
    int maximumSwap(int num) {
      std::string num_str = std::to_string(num);
      int length = num_str.size();
      int max_num = num;
      for (int i = 0; i < length; ++i) {
        for (int j = i + 1; j < length; ++j) {
          if (num_str[i] < num_str[j]) {
            auto temp_str = num_str;
            std::swap(temp_str[i], temp_str[j]);
            max_num = std::max(std::stoi(temp_str), max_num);
          }
        }
      }
      return max_num;
    }
};

int main(int argc, char* argv[]) {
  Solution sl{};
  int num = 9973;
  int ans = sl.maximumSwap(num);
  std::cout << ans << std::endl;
}
