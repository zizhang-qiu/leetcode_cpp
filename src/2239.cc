#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int findClosestNumber(vector<int>& nums) {
    auto cmp = [](const int a, const int b) {
      if (std::abs(a) == std::abs(b)) {
        return a > b;
      }
      return std::abs(a) < std::abs(b);
    };
    std::sort(nums.begin(), nums.end(), cmp);
    return nums[0];
  }
};

int main(int argc, char const* argv[]) {
  Solution sl;
  int res = sl.findClosestNumber(std::vector<int>{-4, -2, 1, 4, 8});
  std::cout << res << std::endl;
  return 0;
}
