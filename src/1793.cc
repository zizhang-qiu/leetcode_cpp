#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maximumScore(vector<int>& nums, int k) {
    int left = k - 1, right = k + 1;
    const int n = nums.size();
    int ans = 0;
    for (int cur_min = nums[k];;) {
      while (left >= 0 && nums[left] >= cur_min) {
        --left;
      }
      while (right < n && nums[right] >= cur_min) {
        ++right;
      }

      ans = std::max(ans, (right - left - 1) * cur_min);
      if (left == -1 && right == n) {
        break;
      }

      cur_min = std::max((left == -1 ? -1 : nums[left]),
                         (right == n ? -1 : nums[right]));
      if (cur_min == -1) {
        break;
      }
    }
    return ans;
  }
};

int main() {
  vector<int> nums = {1, 4, 3, 7, 4, 5};
  int k = 3;
  Solution sl{};
  int ans = sl.maximumScore(nums, k);
  std::cout << ans << std::endl;
}