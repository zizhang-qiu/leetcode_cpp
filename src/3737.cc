#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int countMajoritySubarrays(vector<int>& nums, int target) {
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int cnt = 0;
      for (int j = i; j < n; ++j) {
        cnt += (nums[j] == target ? 1 : -1);
        if (cnt > 0) {
          ++ans;
        }
      }
    }
    return ans;
  }
};

int main() {
  Solution sl;
  std::vector<int> nums = {1, 1, 1, 1};
  int res = sl.countMajoritySubarrays(nums, 4);
  std::cout << res << std::endl;
  return 0;
}