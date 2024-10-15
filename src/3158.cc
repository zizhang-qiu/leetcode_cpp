#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int duplicateNumbersXOR(vector<int>& nums) {
    std::unordered_map<int, int> m;
    for (const int num : nums) {
      ++m[num];
    }
    std::vector<int> duplicate_nums;
    for (const auto& kv : m) {
      if (kv.second == 2) {
        duplicate_nums.push_back(kv.first);
      }
    }
    if (duplicate_nums.empty()) {
      return 0;
    }
    int res = 0;
    for (const int num : duplicate_nums) {
      res ^= num;
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution sl;
  vector nums = {1, 2, 2, 1};
  int res = sl.duplicateNumbersXOR(nums);
  printf("%d", res);
  return 0;
}
