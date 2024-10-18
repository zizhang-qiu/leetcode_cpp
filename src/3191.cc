#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int minOperations(vector<int>& nums) {
    constexpr int num_consecutive_elems = 3;
    const size_t n = nums.size();
    int res = 0;
    for (size_t i = 0; i < n; ++i) {
      if (nums[i] == 0) {
        if (i > n - 3) {
          return -1;
        }

        nums[i] ^= 1;
        nums[i + 1] ^= 1;
        nums[i + 2] ^= 1;
        ++res;
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  Solution sl;
  vector<int> nums = {0, 1, 1, 1, 0, 0};
  int res = sl.minOperations(nums);
  printf("%d", res);
  return 0;
}
