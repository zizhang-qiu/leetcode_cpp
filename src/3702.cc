#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>


using namespace std;

class Solution {
 public:
  int longestSubsequence(vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    bool all_zero = true;
    int total_xor = 0;

    for (int num : nums) {
      total_xor ^= num;
      if (num > 0) {
        all_zero = false;
      }
    }

    if (total_xor > 0) {
      return n;
    }

    return all_zero ? 0 : n - 1;
  }
};

int main() {
    Solution sl;
    std::vector<int> nums = {1, 2, 3};
    int res = sl.longestSubsequence(nums);
    std::cout << res << std::endl;
    return 0;
}