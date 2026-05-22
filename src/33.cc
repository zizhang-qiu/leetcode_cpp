#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    if (nums.empty()) {
      return -1;
    }
    if (nums.size() == 1) {
      return nums[0] == target ? 0 : -1;
    }
    int n = static_cast<int>(nums.size());
    int l = 0, r = n - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (nums[mid] == target) {
        return mid;
      }
      // Left ordered.
      if (nums[0] <= nums[mid]) {
        if (nums[0] <= target && target < nums[mid]) {
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      } else {
        if (nums[mid] < target && target <= nums[n - 1]) {
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }
    }
    return -1;
  }
};

int main() {
    Solution sl;
    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int res = sl.search(nums, 0);
    std::cout << res << "\n";
    return 0;
}