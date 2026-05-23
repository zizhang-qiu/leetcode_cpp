#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool check(vector<int>& nums) {
    int x = 0;
    for (int i = 1; i < static_cast<int>(nums.size()); ++i) {
      if (nums[i] < nums[i - 1]) {
        x = i;
        break;
      }
    }
    if (x == 0) {
      return true;
    }
    for (int i = x + 1; i < static_cast<int>(nums.size()); ++i) {
      if (nums[i] < nums[i - 1]) {
        return false;
      }
    }
    return nums[0] >= nums.back();
  }
};

int main() {
    Solution sl;
    std::vector<int> nums = {3,4,5,1,2};
    std::cout << std::boolalpha << sl.check(nums) << std::endl;
    return 0;
}