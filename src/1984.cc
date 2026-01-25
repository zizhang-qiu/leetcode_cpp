#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumDifference(vector<int>& nums, int k) {

    std::sort(nums.begin(), nums.end());
    int min_diff = std::numeric_limits<int>::max();
    for (size_t i = 0; i < nums.size() - k + 1; i++) {
      int diff = nums[i + k - 1] - nums[i];
      min_diff = std::min(min_diff, diff);
    }
    return min_diff;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  Solution s;
  vector<int> nums = {9, 4, 1, 7};
  int k = 2;
  std::cout << s.minimumDifference(nums, k) << std::endl;
  return 0;
}
